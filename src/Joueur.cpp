//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Joueur.h"

Joueur::Joueur(std::string pseudo, const char img)
    : pseudo(pseudo), img(img) {}

const std::string Joueur::getPseudo() const {
    return pseudo;
}

const char Joueur::getImg() const {
    return img;
}