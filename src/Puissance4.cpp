//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Puissance4.h"
#include <iostream>

Puissance4::Puissance4(std::string pseudo)
    : Jeux("Fatih", 'X', 'O', 4, 7, "Puissance4") {}

std::shared_ptr<Joueur> Puissance4::checkAlignement() {
    auto grille = Jeux::getGrille();
    auto grilleDeJeu = Jeux::getGrille().getGrilleDeJeu();

    // Vérifier les horizontales
    for (int i = 0; i < grille.getNbLignes(); i++) {
        for (int j = 0; j < grille.getNbColonnes() - 3; j++) {// -3 car nous cherchons une séquence de 4
            if (grilleDeJeu[i][j]->getImg() != '\0' &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i][j + 1]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i][j + 2]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i][j + 3]->getImg()) {
                return grilleDeJeu[i][j]->getJoueePar();
            }
        }
    }

    // Vérifier les verticales
    for (int j = 0; j < grille.getNbColonnes(); j++) {
        for (int i = 0; i < grille.getNbLignes() - 3; i++) {// -3 pour la même raison
            if (grilleDeJeu[i][j]->getImg() != '\0' &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 1][j]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 2][j]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 3][j]->getImg()) {
                return grilleDeJeu[i][j]->getJoueePar();
            }
        }
    }

    // Vérifier les diagonales (haut-gauche vers bas-droite)
    for (int i = 0; i < grille.getNbLignes() - 3; i++) {
        for (int j = 0; j < grille.getNbColonnes() - 3; j++) {
            if (grilleDeJeu[i][j]->getImg() != '\0' &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 1][j + 1]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 2][j + 2]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i + 3][j + 3]->getImg()) {
                return grilleDeJeu[i][j]->getJoueePar();
            }
        }
    }

    // Vérifier les diagonales (bas-gauche vers haut-droite)
    for (int i = 3; i < grille.getNbLignes(); i++) {
        for (int j = 0; j < grille.getNbColonnes() - 3; j++) {
            if (grilleDeJeu[i][j]->getImg() != '\0' &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i - 1][j + 1]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i - 2][j + 2]->getImg() &&
                grilleDeJeu[i][j]->getImg() == grilleDeJeu[i - 3][j + 3]->getImg()) {
                return grilleDeJeu[i][j]->getJoueePar();
            }
        }
    }

    return nullptr;
}

//TODO: La méthode de vérification du pion pourrait être déplacer ailleur... et n'est pas optimisé !
void Puissance4::demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur) {
    Jeux::getGrille().afficheGrillePuissance4();

    //TODO: S'il ne reste plus de pions lancer une exception pour arreter, personne n'a gagné.
    auto pionsPossibles = Jeux::getGrille().getEmplacementLibre();

    int idPionJoueeConverti = 0;
    int idPionJouee = 0;
    bool idPionEstValide = false;
    while (!idPionEstValide) {
        std::cout << "Quelle colonne jouer ? (" << joueur->getPseudo() << ") : ";
        idPionJouee = joueur->jouer();
        std::cout << std::endl;

        for (int i = 3; i > -1 && !idPionEstValide; i--) {
            if (idPionJouee < 1 || idPionJouee > Jeux::getGrille().getNbColonnes())
                break;

            idPionJoueeConverti = idPionJouee + ((Jeux::getGrille().getNbColonnes()) * i);
            for (auto pion: pionsPossibles) {
                if (idPionJoueeConverti == pion->getId() && pion->getImg() == '\0') {
                    idPionEstValide = true;
                    break;
                }
            }
        }

        // TODO: prévoir si un enum dans Joueur pour savoir si c'est IA et annulé l'affichge du msg suivant et ci-dessus...
        if (!idPionEstValide)
            std::cout << "Pion invalide de " << joueur->getPseudo() << std::endl;
    }

    Jeux::getGrille().joueurAJouee(joueur, idPionJoueeConverti);
}

std::shared_ptr<Joueur> Puissance4::checkVainqueur() {
    std::shared_ptr<Joueur> vainqueur = checkAlignement();
    if (vainqueur != nullptr) {
        std::cout << "Le joueur " << vainqueur->getPseudo() << " à gagnée !" << std::endl;
        return vainqueur;
    }

    return nullptr;
}