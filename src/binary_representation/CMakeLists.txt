cmake_minimum_required(VERSION 3.10)
project(binary_project C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Основная программа
add_executable(binary main.c binary.c)

# Программа для тестов
add_executable(tests tests.c binary.c)

# Установка флагов компиляции
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(binary PRIVATE -Wall -Wextra)
    target_compile_options(tests PRIVATE -Wall -Wextra)
endif()

# Цель для запуска всех тестов
add_custom_target(run_tests
    COMMAND ./tests
    DEPENDS tests
    COMMENT "Running tests..."
)
