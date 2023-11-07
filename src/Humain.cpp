//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Humain.h"
#include <iostream>

Humain::Humain(std::string pseudo, const char img)
    : Joueur(pseudo, img) {}

const int Humain::jouer() const {
    int idPion = 0;

    std::cin >> idPion;

    return idPion;
}