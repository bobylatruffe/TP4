//
// Created by Fatih BOZLAK on 04/11/2023.
//

#include "IA.h"

IA::IA(std::string pseudo) : Joueur(pseudo, TypeDeJoueur::IA_PLAYER) {}

std::shared_ptr<Pion> IA::jouer(std::vector<shared_ptr<Pion>> &pionsPossible) {
    srand(time(nullptr));

    return pionsPossible[rand() % pionsPossible.size()];
}