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
public:
    Grille(int nbLignes, int nbColonnes);
    void joueurAJouee(const std::shared_ptr<Joueur> joueur, const int idPion);
    void afficheGrille() const;
    void afficheGrillePuissance4() const;
    const int getNbLignes();
    const int getNbColonnes();
    const std::vector<std::vector<std::shared_ptr<Pion>>> getGrilleDeJeu() const;
    const std::vector<std::shared_ptr<Pion>> getEmplacementLibre();
    void initGrille(const char img);
    bool estRemplie();
private:
    const int nbLignes, nbColonnes;

    std::vector<std::vector<std::shared_ptr<Pion>>> grilleDeJeu;
    

    std::shared_ptr<Pion> rechercherPionAvecId(const int idPion);
};

#endif//TP3_GRILLE_H
