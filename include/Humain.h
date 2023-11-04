//
// Created by Fatih BOZLAK on 04/11/2023.
//

#ifndef TP3_HUMAIN_H
#define TP3_HUMAIN_H

#include "Joueur.h"

class Humain : public Joueur {
public:
    Humain(std::string pseudo);

    std::shared_ptr<Pion> jouer(vector<std::shared_ptr<Pion>>& pionsPossibles) override;
};

#endif //TP3_HUMAIN_H
