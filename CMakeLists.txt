cmake_minimum_required(VERSION 3.28)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        question1/validKnightMoves.c
        helpersFuncs.c
        question2/displayChessBoard.c
        question2/displayChessBoard.h)
