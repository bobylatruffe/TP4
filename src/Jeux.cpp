//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Jeux.h"
#include "Humain.h"
#include "Ia.h"

Jeux::Jeux(std::string pseudo, const char imgJoueur1, const char imgJoueur2, const int nbLignes, const int nbColonnes, const std::string nomDuJeu)
    : grille(Grille(nbLignes, nbColonnes)),
      joueurs(2),
      nomDuJeu(nomDuJeu) {
    this->joueurs[0] = std::make_shared<Humain>(pseudo, imgJoueur1);
    this->joueurs[1] = std::make_shared<Ia>("UneIaDeMerde", imgJoueur2);
}

Grille Jeux::getGrille() {
    return grille;
}

std::vector<std::shared_ptr<Joueur>> Jeux::getJoueurs() {
    return joueurs;
}

void Jeux::demarrerPartie() {
    grille.initGrille('\0');
    int i = 0;
    while (true) {
        if (i == 2) 
        {
            i = 0;
        }
        demanderAJoueurDeJouer(Jeux::getJoueurs()[i++]);

        if (checkVainqueur()|| grille.estNulle())
        {
            break;
        } 
    }
}

const std::string Jeux::getTitre() const {
    return nomDuJeu;
}