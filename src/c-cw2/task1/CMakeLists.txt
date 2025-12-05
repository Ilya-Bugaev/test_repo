cmake_required(VERSION 3.10)
project(palindrome_check C)

# Настройка стандарта C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Основная программа с тестами (все в одном файле)
add_executable(palindrome_program
    task1-2.c
)

# Установка свойств
set_target_properties(palindrome_program PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
)