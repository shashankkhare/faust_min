cmake_minimum_required(VERSION 3.10)

project(faust_min_library VERSION 0.1.0 LANGUAGES C CXX)

# Add Oboe for Android
if (ANDROID)
    find_package(oboe REQUIRED CONFIG)
endif()

# Automatically compile Faust .dsp files into C++ headers when their timestamps change
file(GLOB DSP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/../assets/dsp/*.dsp")
foreach(DSP_FILE ${DSP_FILES})
    get_filename_component(DSP_NAME ${DSP_FILE} NAME_WE)
    string(SUBSTRING ${DSP_NAME} 0 1 FIRST_LETTER)
    string(TOUPPER ${FIRST_LETTER} FIRST_LETTER_UPPER)
    string(SUBSTRING ${DSP_NAME} 1 -1 REMAINING_LETTERS)
    set(CAP_NAME "${FIRST_LETTER_UPPER}${REMAINING_LETTERS}")
    set(HPP_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Faust${CAP_NAME}DSP.hpp")
    
    add_custom_command(
        OUTPUT ${HPP_FILE}
        COMMAND faust -lang cpp -es 1 -single -ftz 1 -cn Faust${CAP_NAME}DSP ${DSP_FILE} -o ${HPP_FILE}
        DEPENDS ${DSP_FILE}
        COMMENT "Auto-compiling Faust DSP: ${DSP_NAME} -> Faust${CAP_NAME}DSP.hpp"
    )
    list(APPEND FAUST_GENERATED_HEADERS ${HPP_FILE})
endforeach()
add_custom_target(compile_faust_dsps DEPENDS ${FAUST_GENERATED_HEADERS})
 
add_library(faust_min SHARED
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
  "UMLParser.cpp"
  "SequenceOrchestrator.cpp"
  "FaustMixer.cpp"
  "InstrumentMapper.cpp"
)
 
add_dependencies(faust_min compile_faust_dsps)
 
target_compile_options(faust_min PRIVATE -O3 -ffast-math)
 
target_include_directories(faust_min PRIVATE 
    "."
    "/home/shashankkhare/faust_sdk/faust_src/architecture"
)
 
# Link to the local libfaust.so we just downloaded
target_link_libraries(faust_min PRIVATE 
    "/home/shashankkhare/faust_sdk/lib/libfaust.so"
)
 
set_target_properties(faust_min PROPERTIES
    PUBLIC_HEADER faust_min.h
    INSTALL_RPATH "/home/shashankkhare/faust_sdk/lib"
    BUILD_WITH_INSTALL_RPATH TRUE
    OUTPUT_NAME "faust_min"
)
 
target_compile_definitions(faust_min PUBLIC DART_SHARED_LIB)

if (ANDROID)
  target_link_options(faust_min PRIVATE "-Wl,-z,max-page-size=16384")
  target_link_libraries(faust_min PRIVATE oboe::oboe)
endif()
