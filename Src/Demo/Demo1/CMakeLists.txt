cmake_minimum_required(VERSION 3.1)

project(Demo1)

m_add_source_group_recursive()

add_executable(${PROJECT_NAME} ${sources})

target_link_libraries(${PROJECT_NAME} jsoncpp_lib_static)

m_add_project_pch_std()