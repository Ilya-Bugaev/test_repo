cmake_minimum_required(VERSION 3.25)

project(Dijkstra_algjrythm C)

add_library(stack stack.c)

add_executable(Dijkstra Dijkstra.c)

target_link_libraries(Dijkstra PRIVATE stack)
