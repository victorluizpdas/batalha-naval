cmake_minimum_required(VERSION 3.5)

project(BatalhaNaval)

include(ExternalProject)

ExternalProject_Add(
    termcolor_project
    GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
    GIT_TAG origin/master
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(termcolor_project SOURCE_DIR)

set(CMAKE_CXX_STANDARD 11)

include_directories(${SOURCE_DIR}/include)

add_library(termcolor INTERFACE IMPORTED)
add_dependencies(termcolor termcolor_project)

add_executable(BatalhaNaval main.cpp)

target_link_libraries(BatalhaNaval PRIVATE termcolor)

set_target_properties(BatalhaNaval PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "C:/Users/Victor/Desktop/batalha naval"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "C:/Users/Victor/Desktop/batalha naval"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "C:/Users/Victor/Desktop/batalha naval"
)