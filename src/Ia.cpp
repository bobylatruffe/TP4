//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Ia.h"
#include <ctime>

Ia::Ia(std::string pseudo, const char img)
    : Joueur(pseudo, img) {}

const int Ia::jouer() const {
    //TODO : Limiter au place disponnible !

    return (rand() % 9) + 1;
}