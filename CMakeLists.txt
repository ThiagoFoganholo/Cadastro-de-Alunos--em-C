cmake_minimum_required(VERSION 3.28)
project(struct_com_ponteiros C)

set(CMAKE_C_STANDARD 23)

add_executable(struct_com_ponteiros main.c
        AlunosDaEscola.c
        AlunosDaEscola.h)
