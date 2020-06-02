cmake_minimum_required(VERSION 3.1)

project(JsonCppDemo)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Lib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_UTILITY_ROOT})
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})
include(Common)

find_package(jsoncpp REQUIRED
	PATHS ${JSONCPP_ROOT}
)
MESSAGE("jsoncppinc: " ${jsoncpp_INCLUDE_DIR})

add_subdirectory(Src)

set_target_properties(Demo1 PROPERTIES FOLDER "Demo")
set_target_properties(Demo2 PROPERTIES FOLDER "Demo")