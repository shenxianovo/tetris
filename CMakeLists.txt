cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CXX_STADARD 20)

aux_source_directory(. src)
add_executable(tetris ${src})