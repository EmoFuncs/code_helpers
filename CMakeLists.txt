cmake_minimum_required(VERSION 3.5)

project(code_helpers)

include_directories(3rd_parties/tclap-1.4.0-rc1/include)
include_directories(utils)

add_executable(run run.cpp)
add_executable(create create.cpp)

set_property(TARGET run PROPERTY CXX_STANDARD 17)
set_property(TARGET create PROPERTY CXX_STANDARD 17)