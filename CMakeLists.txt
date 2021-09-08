cmake_minimum_required(VERSION 3.16)
project(Chat)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chat main.cpp Observer.h Subject.h Messaggio.cpp Messaggio.h)