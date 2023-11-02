cmake_minimum_required(VERSION 3.26)
project(TP3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
        TP3 src/main.cpp
        include/Pion.h
        src/Pion.cpp
        include/JoueurException.h
        src/JoueurException.cpp
        include/Joueur.h
        src/Joueur.cpp
)
