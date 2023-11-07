//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Ia.h"
#include <ctime>

Ia::Ia(std::string pseudo, const char img)
    : Joueur(pseudo, img) {}

const int Ia::jouer() const {
//    srand(time(nullptr));
    return (rand() % 9) + 1;
}