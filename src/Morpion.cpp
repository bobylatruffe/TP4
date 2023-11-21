//
// Created by Fatih BOZLAK on 07/11/2023.
//

#include "Morpion.h"
#include "Humain.h"
#include "Ia.h"
#include <iostream>

Morpion::Morpion(std::string pseudo)
    : Jeux("Fatih", 'X', 'O', 3, 3, "Morpion") {}

//TODO: La méthode de vérification du pion pourrait être déplacer ailleur... et n'est pas optimisé !
void Morpion::demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur) {
    Jeux::getGrille().afficheGrille();

    //TODO: S'il ne reste plus de pions lancer une exception pour arreter, personne n'a gagné.
    auto pionsPossibles = Jeux::getGrille().getEmplacementLibre();

    int idPionJouee = 0;
    bool idPionEstValide = false;

    std::cout << "Quelle case jouer ? (" << joueur->getPseudo() << ") : ";
    while (!idPionEstValide) {
      
        idPionJouee = joueur->jouer();
        std::cout << std::endl;
      
        for (auto pion: pionsPossibles) 
        {
            if (idPionJouee == pion->getId()) idPionEstValide = true;
        }

        if (!(joueur->getPseudo()=="UneIaDeMerde")&& !idPionEstValide)
        {
            std::cout << "Pion invalide de " << joueur->getPseudo() << std::endl;
        }
    }

    Jeux::getGrille().joueurAJouee(joueur, idPionJouee);
}

bool Morpion::estNulle()
{
    if(getGrille().estRemplie())
    {
        std::cout << "Egalité !"<< std::endl;
    }
    return getGrille().estRemplie();
}

std::shared_ptr<Joueur> Morpion::checkHorizontales() {
    std::vector<std::vector<std::shared_ptr<Pion>>> grilleDeJeu = Jeux::getGrille().getGrilleDeJeu();

    for (int i = 0; i < Jeux::getGrille().getNbLignes(); i++) {
        std::shared_ptr<Pion> pionDeRef = grilleDeJeu[i][0];
        int nbHorizontales = 0;

        for (int j = 0; j < Jeux::getGrille().getNbColonnes(); j++) {

            if (pionDeRef->getImg() != '\0' && pionDeRef->getImg() == grilleDeJeu[i][j]->getImg())
                nbHorizontales++;
        }

        if (nbHorizontales == 3)
            return pionDeRef->getJoueePar();
    }

    return nullptr;
}

std::shared_ptr<Joueur> Morpion::checkVerticales() {
    std::vector<std::vector<std::shared_ptr<Pion>>> grilleDeJeu = Jeux::getGrille().getGrilleDeJeu();

    for (int j = 0; j < Jeux::getGrille().getNbColonnes(); j++) {
        std::shared_ptr<Pion> pionDeRef = grilleDeJeu[0][j];
        int nbVerticales = 0;

        for (int i = 0; i < Jeux::getGrille().getNbLignes(); i++) {
            if (pionDeRef->getImg() != '\0' && pionDeRef->getImg() == grilleDeJeu[i][j]->getImg())
                nbVerticales++;
        }

        if (nbVerticales == 3)
            return pionDeRef->getJoueePar();
    }

    return nullptr;
}

std::shared_ptr<Joueur> Morpion::checkDiagonales() {
    std::vector<std::vector<std::shared_ptr<Pion>>> grilleDeJeu = Jeux::getGrille().getGrilleDeJeu();

    std::shared_ptr<Pion> pionDeRefDiagPrinc = grilleDeJeu[0][0];
    std::shared_ptr<Pion> pionDeRefDiagSec = grilleDeJeu[0][Jeux::getGrille().getNbColonnes() - 1];
    int nbDiagPrinc = 0, nbDiagSec = 0;

    for (int i = 0; i < Jeux::getGrille().getNbLignes(); i++) {
        // Vérifie la diagonale principale (haut gauche vers bas droit)
        if (pionDeRefDiagPrinc->getImg() != '\0' && pionDeRefDiagPrinc->getImg() == grilleDeJeu[i][i]->getImg()) {
            nbDiagPrinc++;
        }

        // Vérifie la diagonale secondaire (haut droit vers bas gauche)
        if (pionDeRefDiagSec->getImg() != '\0' && pionDeRefDiagSec->getImg() == grilleDeJeu[i][Jeux::getGrille().getNbColonnes() - 1 - i]->getImg()) {
            nbDiagSec++;
        }
    }

    // Si une des diagonales est complète avec le même symbole non-vide, retourne le joueur correspondant
    if (nbDiagPrinc == 3) {
        return pionDeRefDiagPrinc->getJoueePar();
    } else if (nbDiagSec == 3) {
        return pionDeRefDiagSec->getJoueePar();
    }

    return nullptr;
}

std::shared_ptr<Joueur> Morpion::checkVainqueur() {
    std::shared_ptr<Joueur> vainqueur = checkHorizontales();
    if (vainqueur != nullptr) {
        std::cout << "Le joueur " << vainqueur->getPseudo() << " à gagnée !" << std::endl;
        return vainqueur;
    }

    vainqueur = checkVerticales();
    if (vainqueur != nullptr) {
        std::cout << "Le joueur " << vainqueur->getPseudo() << " à gagnée !" << std::endl;
        return vainqueur;
    }

    vainqueur = checkDiagonales();
    if (vainqueur != nullptr) {
        std::cout << "Le joueur " << vainqueur->getPseudo() << " à gagnée !" << std::endl;
        return vainqueur;
    }

    return nullptr;
}