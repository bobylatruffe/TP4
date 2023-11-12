//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_HUMAIN_H
#define TP3_HUMAIN_H
#include "Joueur.h"
#include <string>
class Humain : public Joueur {
public:
    Humain(std::string pseudo, const char img);

    const int jouer() const override;
};
#endif//TP3_HUMAIN_H
