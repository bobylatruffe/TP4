cmake_minimum_required(VERSION 3.26)
project(TP3)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(
        TP3
        src/main.cpp
        include/Grille.h
        include/Pion.h
        src/Pion.cpp
        src/Grille.cpp
        include/Joueur.h
        src/Joueur.cpp
        include/Humain.h
        src/Humain.cpp
        include/Ia.h
        src/Ia.cpp
        include/Morpion.h
        src/Morpion.cpp
        include/Jeux.h
        src/Jeux.cpp
)
