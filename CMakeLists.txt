cmake_minimum_required (VERSION 3.5)

project ("HttpsImpl")

aux_source_directory(src all_src)
add_executable (HttpsImpl ${all_src})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HttpsImpl PROPERTY CXX_STANDARD 20)
endif()
