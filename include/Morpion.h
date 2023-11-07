//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_MORPION_H
#define TP3_MORPION_H
#include "Grille.h"
#include "Jeux.h"
#include "Joueur.h"
#include <memory>
#include <vector>
class Morpion : public Jeux {
private:
    void demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur);

    std::shared_ptr<Joueur> checkHorizontales();
    std::shared_ptr<Joueur> checkVerticales();
    std::shared_ptr<Joueur> checkDiagonales();

    std::shared_ptr<Joueur> checkVainqueur() override;

public:
    Morpion(std::string pseudo);
    void demarrerPartie() override;
};
#endif//TP3_MORPION_H
