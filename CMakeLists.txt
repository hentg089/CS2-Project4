cmake_minimum_required(VERSION 3.24)
project(project4)

set(CMAKE_CXX_STANDARD 17)

add_executable(project4 main.cpp LinkedStack.h Node.h  Node.cpp StackInterface.h LinkedStack.cpp Infix.cpp Infix.h
        DivideByZero.cpp DivideByZero.h)
