//
// Created by Fatih BOZLAK on 02/11/2023.
//

#ifndef TP3_JOUEUR_H
#define TP3_JOUEUR_H

#include "Pion.h"
#include <memory>
#include <vector>

using namespace std;

enum TypeDeJoueur {
    HUMAIN_PLAYER,
    IA_PLAYER
};

class Joueur {
private:
    const string pseudo;
    const TypeDeJoueur typeDeJoueur;

public:
    Joueur(string pseudo, TypeDeJoueur typeDeJoueur);

    [[nodiscard]] string getPseudo() const;

    virtual std::shared_ptr<Pion> jouer(vector<std::shared_ptr<Pion>> &pionsPossibles) = 0;
};

#endif//TP3_JOUEUR_H
