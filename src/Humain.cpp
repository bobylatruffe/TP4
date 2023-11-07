//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Humain.h"
#include <iostream>

Humain::Humain(std::string pseudo, const char img)
    : Joueur(pseudo, img) {}

const int Humain::jouer() const {
    int idPion = 0;
    //    while (idPion < 1 || idPion > pionsPossibles.size()) {
    std::cout << "Quelle case jouer ? ";
    std::cin >> idPion;
    //    }

    return idPion;
}