cmake_minimum_required(VERSION 3.10)

project(faust_min_library VERSION 0.1.0 LANGUAGES C CXX)

add_library(faust_min SHARED
  "faust_min.cpp"
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
  "FaustBell.cpp"
)

set_target_properties(faust_min PROPERTIES
  PUBLIC_HEADER faust_min.h
  OUTPUT_NAME "faust_min"
)

target_compile_definitions(faust_min PUBLIC DART_SHARED_LIB)

if (ANDROID)
  target_link_options(faust_min PRIVATE "-Wl,-z,max-page-size=16384")
endif()
