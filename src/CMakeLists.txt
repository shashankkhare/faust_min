cmake_minimum_required(VERSION 3.10)

project(faust_min_library VERSION 0.1.0 LANGUAGES C CXX)

# Add Oboe for Android
if (ANDROID)
    add_subdirectory("../deps/oboe" "${CMAKE_BINARY_DIR}/oboe" EXCLUDE_FROM_ALL)
    include_directories("../deps/oboe/include")
endif()

# Automatically compile Faust .dsp files into C++ headers when their timestamps change
file(GLOB DSP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../assets/dsp/*.dsp")
foreach(DSP_FILE ${DSP_FILES})
    get_filename_component(DSP_NAME ${DSP_FILE} NAME_WE)
    string(SUBSTRING ${DSP_NAME} 0 1 FIRST_LETTER)
    string(TOUPPER ${FIRST_LETTER} FIRST_LETTER_UPPER)
    string(SUBSTRING ${DSP_NAME} 1 -1 REMAINING_LETTERS)
    set(CAP_NAME "${FIRST_LETTER_UPPER}${REMAINING_LETTERS}")
    # Handle capitalization edge cases
    if (DSP_NAME STREQUAL "master_reverb")
        set(CAP_NAME "MasterReverb")
    endif()
    if (DSP_NAME STREQUAL "track_fx")
        set(CAP_NAME "TrackFx")
    endif()
    set(HPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Faust${CAP_NAME}DSP.hpp")
    
    # All DSPs that import("fm.lib") depend on it
    set(LIB_DEPS "")
    list(APPEND LIB_DEPS "${CMAKE_CURRENT_SOURCE_DIR}/../assets/dsp/fm.lib")
    add_custom_command(
        OUTPUT ${HPP_FILE}
        COMMAND faust -lang cpp -es 1 -single -ftz 1 -I ${CMAKE_CURRENT_SOURCE_DIR}/faust_arch -cn Faust${CAP_NAME}DSP ${DSP_FILE} -o ${HPP_FILE}
        DEPENDS ${DSP_FILE} ${LIB_DEPS}
        COMMENT "Auto-compiling Faust DSP: ${DSP_NAME} (-single) -> Faust${CAP_NAME}DSP.hpp"
    )
    list(APPEND FAUST_GENERATED_HEADERS ${HPP_FILE})
    
    # Establish direct dependency so that C++ object files recompile when the generated header changes
    set(CPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Faust${CAP_NAME}.cpp")
    if (EXISTS ${CPP_FILE})
        set_source_files_properties(${CPP_FILE} PROPERTIES OBJECT_DEPENDS ${HPP_FILE})
    endif()
endforeach()

# FaustInstrument.cpp includes ALL generated hpp headers — ensure it recompiles when any hpp changes
set_source_files_properties("FaustInstrument.cpp" PROPERTIES OBJECT_DEPENDS "${FAUST_GENERATED_HEADERS}")
add_custom_target(compile_faust_dsps DEPENDS ${FAUST_GENERATED_HEADERS})
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FAUST_MIN_SOURCES
  "faust_min.cpp"
  "FaustInstrument.cpp"
  "FaustFlute.cpp"
  "FaustBowl.cpp"
  "FaustDayan.cpp"
  "FaustBayan.cpp"
  "FaustSitar.cpp"
  "FaustKick.cpp"
  "FaustSnare.cpp"
  "FaustTom.cpp"
  "FaustHiHat.cpp"
  "FaustRide.cpp"
  "FaustCowbell.cpp"
  "FaustBell.cpp"
  "FaustTanpura.cpp"
  "FaustPiano.cpp"
  "FaustSax.cpp"
  "FaustTrumpet.cpp"
  "FaustShakuhachi.cpp"
  "FaustBansuri.cpp"
  "FaustViolin.cpp"
  "FaustTibetanbowl.cpp"
  "UMLParser.cpp"
  "UMLSequence.cpp"
  "SequenceOrchestrator.cpp"
  "FaustMixer.cpp"
  "InstrumentMapper.cpp"
  ${FAUST_GENERATED_HEADERS}
)

add_library(faust_min SHARED ${FAUST_MIN_SOURCES})

# Static build of the same engine so test binaries can link the DSPs
# directly instead of resolving libfaust_min.so at runtime.
add_library(faust_min_static STATIC ${FAUST_MIN_SOURCES})
target_compile_options(faust_min_static PRIVATE -O3 -ffast-math -ftree-vectorize $<$<CONFIG:Release>:-flto>)
target_include_directories(faust_min_static PRIVATE
    "."
    "faust_arch"
)
target_compile_definitions(faust_min_static PUBLIC DART_SHARED_LIB)

add_dependencies(faust_min compile_faust_dsps)
add_dependencies(faust_min_static compile_faust_dsps)

# Sync CSV lookup tables from plugin assets to main application assets post-build
file(GLOB CSV_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../assets/dsp/*.csv")
foreach(CSV_FILE ${CSV_FILES})
    get_filename_component(CSV_NAME ${CSV_FILE} NAME)
    # Copy to source assets (for Flutter bundle)
    add_custom_command(
        TARGET faust_min POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CSV_FILE}
        "${CMAKE_SOURCE_DIR}/../assets/dsp/${CSV_NAME}"
        COMMENT "Syncing CSV lookup table to main assets: ${CSV_NAME}"
    )
    # Also copy to build dir for test binaries (running from build-release/)
    add_custom_command(
        TARGET faust_min POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/assets/dsp"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CSV_FILE}
        "${CMAKE_BINARY_DIR}/assets/dsp/${CSV_NAME}"
        COMMENT "Copying CSV to build directory: ${CSV_NAME}"
    )
endforeach()
 
target_compile_options(faust_min PRIVATE -O3 -ffast-math -ftree-vectorize $<$<CONFIG:Release>:-flto>)
 
target_include_directories(faust_min PRIVATE 
    "."
    "faust_arch"
)
 
# Link to libfaust for interpreter support
if (NOT ANDROID AND NOT CMAKE_CROSSCOMPILING)
    find_library(FAUST_LIB NAMES faust libfaust
        PATHS /usr/lib /usr/lib/x86_64-linux-gnu /usr/local/lib /home/shashankkhare/faust_sdk/lib)
    if (FAUST_LIB)
        target_link_libraries(faust_min PRIVATE ${FAUST_LIB})
        target_link_libraries(faust_min_static PRIVATE ${FAUST_LIB})
        message(STATUS "Found libfaust: ${FAUST_LIB}")
    else()
        message(WARNING "libfaust not found — interpreter mode disabled on this platform")
        target_compile_definitions(faust_min PRIVATE FAUST_DISABLE_INTERPRETER)
    endif()
else()
    message(STATUS "libfaust skipped (cross-compile or Android) — interpreter mode disabled")
    target_compile_definitions(faust_min PRIVATE FAUST_DISABLE_INTERPRETER)
endif()
 
set_target_properties(faust_min PROPERTIES
    PUBLIC_HEADER faust_min.h
    OUTPUT_NAME "faust_min"
)
 
target_compile_definitions(faust_min PUBLIC DART_SHARED_LIB)

if (ANDROID)
  target_link_options(faust_min PRIVATE "-Wl,-z,max-page-size=16384")
  target_link_libraries(faust_min PRIVATE oboe)
endif()

# =====================================================
# TEST BINARIES (Linux desktop only)
# =====================================================
set(FAUST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/faust_arch")

if(NOT CMAKE_CROSSCOMPILING)
set(TEST_COMMON_LINK
    faust_min_static
    ${FAUST_LIB}
    pthread
    dl
)

set(TEST_COMMON_COMPILE -O3 -ffast-math)

macro(add_faust_test NAME SOURCE)
    add_executable(${NAME} ${SOURCE})
    target_compile_options(${NAME} PRIVATE ${TEST_COMMON_COMPILE})
    target_include_directories(${NAME} PRIVATE "." ${FAUST_INCLUDE_DIR})
    target_link_libraries(${NAME} PRIVATE ${TEST_COMMON_LINK})
    if (FAUST_LIB)
        set_target_properties(${NAME} PROPERTIES
            INSTALL_RPATH "${CMAKE_BINARY_DIR}"
            BUILD_WITH_INSTALL_RPATH TRUE
            LINK_FLAGS "-rdynamic"
        )
    endif()
endmacro()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../test/test_instruments.cpp")
    add_faust_test(test_instruments "../test/test_instruments.cpp")
    target_link_libraries(test_instruments PRIVATE fftw3)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../test/test_mixer.cpp")
    add_faust_test(test_mixer "../test/test_mixer.cpp")
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../test/test_sequence.cpp")
    add_faust_test(test_sequence "../test/test_sequence.cpp")
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../test/test_orchestrator.cpp")
    add_executable(test_orchestrator "../test/test_orchestrator.cpp")
    target_compile_options(test_orchestrator PRIVATE ${TEST_COMMON_COMPILE})
    target_include_directories(test_orchestrator PRIVATE "." ${FAUST_INCLUDE_DIR})
    target_link_libraries(test_orchestrator PRIVATE ${TEST_COMMON_LINK} faust_min)
    set_target_properties(test_orchestrator PROPERTIES
        EXCLUDE_FROM_ALL ON
    )
endif()

endif()
