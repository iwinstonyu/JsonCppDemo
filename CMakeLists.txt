cmake_minimum_required(VERSION 3.1)

project(JsonCppDemo)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/CMake")
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})
include(Common)

find_package(jsoncpp REQUIRED
 	PATHS "C:/External/jsoncpp/1.8.4/Visual_Studio_15_2017/lib/cmake/jsoncpp")
	
message("jsoncpp version: " ${jsoncpp_FIND_VERSION})

add_subdirectory(Src)

set_target_properties(Demo1 PROPERTIES FOLDER "Demo")
set_target_properties(Demo2 PROPERTIES FOLDER "Demo")