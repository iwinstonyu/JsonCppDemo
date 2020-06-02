cmake_minimum_required(VERSION 3.1)

m_source_group_recurse(sources)

add_executable(Demo2 ${sources})

target_link_libraries(Demo2 jsoncpp_lib_static)