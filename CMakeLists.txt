cmake_minimum_required(VERSION 3.22)
project(algoritmos-grafos)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp menu.cpp menu.h grafo.cpp grafo.h algoritmos.cpp algoritmos.h arquivo.cpp arquivo.h)