cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(processi VERSION 0.1.1)
set(PROJECT_COMPANY_NAME "Avasoft")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs")
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Concurrent)





add_executable(${PROJECT_NAME} "pmain.cpp")



qt5_use_modules(processi Core Concurrent Widgets)

message("End line from cmakelist.txt ................ :-)"  ${PROJECT_NAME} )
