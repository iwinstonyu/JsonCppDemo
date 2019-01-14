cmake_minimum_required(VERSION 3.1)

project(JsoncppDemo)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(Common)

add_subdirectory(third_party)
add_subdirectory(Src)

set_target_properties(jsoncpp_check PROPERTIES FOLDER "third_party/jsoncpp")
set_target_properties(jsoncpp_lib_static PROPERTIES FOLDER "third_party/jsoncpp")
set_target_properties(jsoncpp_readerwriter_tests PROPERTIES FOLDER "third_party/jsoncpp")
set_target_properties(jsoncpp_test PROPERTIES FOLDER "third_party/jsoncpp")
set_target_properties(jsontestrunner_exe PROPERTIES FOLDER "third_party/jsoncpp")

set_target_properties(Demo1 PROPERTIES FOLDER "Demo")
set_target_properties(Demo2 PROPERTIES FOLDER "Demo")