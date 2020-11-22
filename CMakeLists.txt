cmake_minimum_required(VERSION 3.17)
project(grafo_dinamico)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafo_dinamico src/ui/main.cpp src/ui/utilitario/Validar.cpp src/ui/utilitario/Validar.h src/tl/Gestor.cpp src/tl/Gestor.h src/bl/Vertice.cpp src/bl/Vertice.h src/bl/Arista.cpp src/bl/Arista.h src/bl/Grafo.cpp src/bl/Grafo.h)