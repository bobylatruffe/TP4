//
// Created by Fatih BOZLAK on 04/11/2023.
//

#ifndef TP3_IA_H
#define TP3_IA_H

#include "Joueur.h"
class IA : public Joueur {
public:
    IA(std::string pseudo);

    std::shared_ptr<Pion> jouer(std::vector<shared_ptr<Pion>> &pionsPossible) override;
};

#endif//TP3_IA_H
