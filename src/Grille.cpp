//
// Created by Fatih BOZLAK on 06/11/2023.
//

#include "Grille.h"
#include <iostream>

Grille::Grille(int nbLignes, int nbColonnes) : nbLignes(nbLignes), nbColonnes(nbColonnes), grilleDeJeu(nbLignes, std::vector<std::shared_ptr<Pion>>(nbColonnes)) {
    initGrille('\0');
}

void Grille::initGrille(const char img) {
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            grilleDeJeu[i][j] = std::make_shared<Pion>('\0', i, j);
        }
    }
}

// TODO: Cette méthode et la _Puissance4 doit être factorisé pour être déporter dans respectivement Morpion et Puissance4
// Ce n'est pas ça bonne place, où la paramétriser ... mais si d'autre jeux sont construit, il faudra chaque fois
// modifier la classe Grille ... Mon objectif serai de ne toucher que la classe du jeux que l'on veut créer !!!
void Grille::afficheGrille() const {
    /* idée pour centrer ? ...
    int offset = to_string(grilleDeJeu[nbLignes - 1][nbColonnes - 1]->getId()).length();
    string offsetString;

    while (offset--) {
        offsetString += " ";
    } */


    std::cout << " --- --- ---" << std::endl;
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            if (grilleDeJeu[i][j]->getJoueePar()) {
                std::cout << "| " << grilleDeJeu[i][j]->getImg() << " ";
                continue;
            }

            std::cout << "| " << grilleDeJeu[i][j]->getId() << " ";
        }

        std::cout << "| " << std::endl;
        std::cout << " --- --- ---" << std::endl;
    }
}

void Grille::afficheGrillePuissance4() const {
    for (int i = 1; i <= nbColonnes; i++) {
        std::cout << "  |   " << i << " ";
    }
    std::cout << "  |" << std::endl;
    std::cout << "  ---------------------------------------------------------" << std::endl;

    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            if (grilleDeJeu[i][j]->getImg() != '\0')
                std::cout << "  |   " << grilleDeJeu[i][j]->getImg() << " ";
            else
                std::cout << "  |     ";

        }

        std::cout << "  |" << std::endl;
        std::cout << "  ---------------------------------------------------------" << std::endl;
    }
}

void Grille::joueurAJouee(const std::shared_ptr<Joueur> joueur, const int idPion) {
    std::shared_ptr<Pion> pionJouee = rechercherPionAvecId(idPion);
    pionJouee->setJoueePar(joueur);
    pionJouee->setImg(joueur->getImg());
}

std::shared_ptr<Pion> Grille::rechercherPionAvecId(const int idPion) {
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            if (grilleDeJeu[i][j]->getId() == idPion)
                return grilleDeJeu[i][j];
        }
    }

    return nullptr;
}

const int Grille::getNbLignes() {
    return nbLignes;
}

const int Grille::getNbColonnes() {
    return nbColonnes;
}

const std::vector<std::vector<std::shared_ptr<Pion>>> Grille::getGrilleDeJeu() const {
    return grilleDeJeu;
}

const std::vector<std::shared_ptr<Pion>> Grille::getEmplacementLibre() {
    std::vector<std::shared_ptr<Pion>> pionsPossibles = std::vector<std::shared_ptr<Pion>>();

    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            if (grilleDeJeu[i][j]->getImg() == '\0')
                pionsPossibles.push_back(grilleDeJeu[i][j]);
        }
    }

    return pionsPossibles;
}