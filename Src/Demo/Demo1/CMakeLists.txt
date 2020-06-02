cmake_minimum_required(VERSION 3.1)

m_source_group_recurse(sources)

add_executable(Demo1 ${sources})

target_link_libraries(Demo1 jsoncpp_lib_static)