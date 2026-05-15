cmake_minimum_required(VERSION 3.10)

project(faust_min_library VERSION 0.1.0 LANGUAGES C CXX)

# Add Oboe for Android
if (ANDROID)
    find_package(oboe REQUIRED CONFIG)
endif()

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
