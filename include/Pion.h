//
// Created by Fatih BOZLAK on 06/11/2023.
//

#ifndef TP3_PION_H
#define TP3_PION_H

#include "Joueur.h"
#include <memory>
class Pion {
public:
    static int next_id;
    Pion(const char img, const int x, const int y);

    const int getId() const;

    void setJoueePar(std::shared_ptr<Joueur> joueur);
    std::shared_ptr<Joueur> getJoueePar() const;

    const char getImg() const;
    void setImg(const char img);
private:

    const int id;
    const int x;
    const int y;

    char img;

    std::shared_ptr<Joueur> joueePar;
};

#endif//TP3_PION_H
