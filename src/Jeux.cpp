//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Jeux.h"
#include "Humain.h"
#include "Ia.h"

Jeux::Jeux(std::string pseudo, const char imgJoueur1, const char imgJoueur2)
    : grille(Grille(3, 3)),
      joueurs(2) {
    this->joueurs[0] = std::make_shared<Humain>(pseudo, imgJoueur1);
    this->joueurs[1] = std::make_shared<Ia>("UneIaDeMerde", imgJoueur2);
}

Grille Jeux::getGrille() {
    return grille;
}

std::vector<std::shared_ptr<Joueur>> Jeux::getJoueurs() {
    return joueurs;
}