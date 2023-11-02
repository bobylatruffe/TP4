//
// Created by Fatih BOZLAK on 02/11/2023.
//

#include "Joueur.h"

Joueur::Joueur(std::string pseudo, TypeDeJoueur typeDeJoueur) : pseudo(pseudo), typeDeJoueur(typeDeJoueur) {}

std::string Joueur::getPseudo() const {
    return this->pseudo;
}