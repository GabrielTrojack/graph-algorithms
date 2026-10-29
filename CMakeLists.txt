cmake_minimum_required(VERSION 3.20)

project(grafo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GRAPHVIZ REQUIRED libgvc)

add_executable(grafo
    main.cpp
    Grafo/Grafo.cpp
    Djikstra/Djikstra.cpp
    DFS/DFS.cpp
    BFS/BFS.cpp
    Toposort/toposort.cpp
    draw/draw.cpp
    Kruskal/Kruskal.cpp
    CFC/cfc.cpp
)

target_include_directories(grafo PRIVATE
    ${GRAPHVIZ_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_directories(grafo PRIVATE
    ${GRAPHVIZ_LIBRARY_DIRS}
)

target_link_libraries(grafo PRIVATE
    ${GRAPHVIZ_LIBRARIES}
)