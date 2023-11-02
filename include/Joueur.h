//
// Created by Fatih BOZLAK on 02/11/2023.
//

#ifndef TP3_JOUEUR_H
#define TP3_JOUEUR_H

#include <iostream>
#include <list>
#include <memory>
#include "Pion.h"

using namespace std;

enum TypeDeJoueur {
    Humain,
    IA
};

class Joueur {
private:
    const string pseudo;
    const TypeDeJoueur typeDeJoueur;

public:
    Joueur(string pseudo, TypeDeJoueur typeDeJoueur);

    [[nodiscard]] string getPseudo() const;

    virtual Pion jouer(list<std::shared_ptr<Pion>> pionsPossibles) const = 0;
};

#endif //TP3_JOUEUR_H
