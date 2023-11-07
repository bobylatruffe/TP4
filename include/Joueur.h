//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_JOUEUR_H
#define TP3_JOUEUR_H

#include <string>
#include <vector>
class Joueur {
private:
    const std::string pseudo;
    const char img;

public:
    Joueur(std::string pseudo, const char img);

    const std::string getPseudo() const;
    const char getImg() const;

    virtual const int jouer() const = 0;
};
#endif//TP3_JOUEUR_H
