cmake_minimum_required(VERSION 3.10)
project(SortedList C)
set(CMAKE_C_STANDARD 99)

add_executable(sorted_list
    sorted_list.c
    s_list.c
    tests.c
)

target_compile_options(sorted_list PRIVATE -Wall -Wextra)

add_custom_target(test
    COMMAND ./sorted_list --test
    DEPENDS sorted_list
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(run
    COMMAND ./sorted_list
    DEPENDS sorted_list
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
