cmake_minimum_required(VERSION 3.10)
project(cyclic_shift)

# Исполняемый файл
add_executable(cyclic_shift task2.c)

# Стандарт C
set_property(TARGET cyclic_shift PROPERTY C_STANDARD 11)
