cmake_minimum_required(VERSION 3.19)
project(Project_dentist C)

set(CMAKE_C_STANDARD 99)

add_executable(Project_dentist main.c BST.c BST.h person.c person.h)