cmake_minimum_required (VERSION 3.5)

project ("HttpsImpl")

# 将源代码添加到此项目的可执行文件。
add_executable (HttpsImpl "src/HttpsImpl.cpp" "src/HttpsImpl.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HttpsImpl PROPERTY CXX_STANDARD 20)
endif()
