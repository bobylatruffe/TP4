//
// Created by Fatih BOZLAK on 06/11/2023.
//

#ifndef TP3_GRILLE_H
#define TP3_GRILLE_H

#include "Joueur.h"
#include "Pion.h"
#include <memory>
#include <vector>

class Grille {
private:
    const int nbLignes, nbColonnes;

    std::vector<std::vector<std::shared_ptr<Pion>>> grilleDeJeu;

    void initGrille(const char img);
    std::shared_ptr<Pion> rechercherPionAvecId(const int idPion);

public:
    Grille(int nbLignes, int nbColonnes);

    void joueurAJouee(const std::shared_ptr<Joueur> joueur, const int idPion);
    void afficheGrille() const;
    const int getNbLignes();
    const int getNbColonnes();
    const std::vector<std::vector<std::shared_ptr<Pion>>> getGrilleDeJeu() const;
    const std::vector<std::shared_ptr<Pion>> getEmplacementLibre();
};

#endif//TP3_GRILLE_H
