cmake_minimum_required(VERSION 3.10)
project(double_formatter C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Основная программа
add_executable(double double.c double_utils.c)

# Тесты
add_executable(tests tests.c double_utils.c)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(double PRIVATE -Wall -Wextra)
    target_compile_options(tests PRIVATE -Wall -Wextra)
endif()

add_custom_target(run_tests
    COMMAND ./tests
    DEPENDS tests
    COMMENT "Running tests..."
)
