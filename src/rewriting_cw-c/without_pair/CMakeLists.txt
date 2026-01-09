cmake_minimum_required(VERSION 3.28)
project(withoutPair)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(withoutPair task1.c)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(withoutPair PRIVATE -Wall -Wextra -Wpedantic)
endif()
