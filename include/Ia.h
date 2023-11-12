//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_IA_H
#define TP3_IA_H
#include "Humain.h"
class Ia : public Joueur {
public:
    Ia(std::string pseudo, const char img);
    const int jouer() const override;
};
#endif//TP3_IA_H
