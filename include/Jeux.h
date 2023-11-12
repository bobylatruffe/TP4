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
    std::string nomDuJeu;

    virtual void demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur) = 0;

    virtual std::shared_ptr<Joueur> checkVainqueur() = 0;

public:
    Jeux(std::string pseudo, const char imgJoueur1, const char imgJoueur2, const int nbLignes, const int nbColonnes, const std::string nomDuJeu);

    Grille getGrille();

    std::vector<std::shared_ptr<Joueur>> getJoueurs();

    const std::string getTitre() const;

    void demarrerPartie();
};
#endif//TP3_JEUX_H
