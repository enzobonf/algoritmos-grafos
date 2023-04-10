cmake_minimum_required(VERSION 3.22)
project(algoritmos-grafos)

set(CMAKE_CXX_STANDARD 11)

include(FindGraphviz.cmake)

add_executable(main main.cpp grafo.cpp grafo.h algoritmos.cpp algoritmos.h arquivo.cpp arquivo.h)

target_include_directories(main PUBLIC ${GRAPHVIZ_INCLUDE_DIRS})
target_link_libraries(main PUBLIC ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY})