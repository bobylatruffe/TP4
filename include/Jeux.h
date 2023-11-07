//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_JEUX_H
#define TP3_JEUX_H
#include "Grille.h"
#include "Joueur.h"
#include <memory>
class Jeux {
private:
    std::vector<std::shared_ptr<Joueur>> joueurs;
    Grille grille;

    void demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur);

    virtual std::shared_ptr<Joueur> checkVainqueur() = 0;

public:
    Jeux(std::string pseudo, const char imgJoueur1, const char imgJoueur2);

    Grille getGrille();
    std::vector<std::shared_ptr<Joueur>> getJoueurs();

    virtual void demarrerPartie() = 0;
};
#endif//TP3_JEUX_H
