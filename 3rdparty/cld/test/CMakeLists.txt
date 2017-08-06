
cmake_minimum_required(VERSION 3.9)
project(xlang)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set (CMAKE_CXX_STANDARD 11)

add_definitions(-DCLD_WINDOWS)

include_directories(/usr/local/include/cld)
include_directories(/Users/dev/sandbox/cld/src)  
add_executable(${PROJECT_NAME} "main.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} /usr/local/lib/libcld.a)

