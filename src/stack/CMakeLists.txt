cmake_minimum_required(VERSION 3.25)

project(sorting_brackets C)

add_library(stack stack.c)

add_executable(advanced_brackets advanced_brackets.c)

target_link_libraries(advanced_brackets PRIVATE stack)
