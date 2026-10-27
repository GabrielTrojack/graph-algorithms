cmake_minimum_required(VERSION 3.20)

project(MeuProjeto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GRAPHVIZ REQUIRED libgvc)

add_executable(meu_programa
    main.cpp
    Grafo/Grafo.cpp
    Djikstra/Djikstra.cpp
    DFS/DFS.cpp
    BFS/BFS.cpp
    Toposort/toposort.cpp
    draw/draw.cpp
    Kruskal/Kruskal.cpp
)

target_include_directories(meu_programa PRIVATE
    ${GRAPHVIZ_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_directories(meu_programa PRIVATE
    ${GRAPHVIZ_LIBRARY_DIRS}
)

target_link_libraries(meu_programa PRIVATE
    ${GRAPHVIZ_LIBRARIES}
)