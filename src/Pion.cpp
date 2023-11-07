//
// Created by Fatih BOZLAK on 06/11/2023.
//

#include "Pion.h"

int Pion::next_id = 1;

Pion::Pion(const char img, const int x, const int y) : img(img), x(x), y(x), id(Pion::next_id++) {}

const int Pion::getId() const {
    return id;
}

void Pion::setJoueePar(std::shared_ptr<Joueur> joueur) {
    joueePar = joueur;
}

std::shared_ptr<Joueur> Pion::getJoueePar() const {
    return joueePar;
}

const char Pion::getImg() const {
    return this->img;
}

void Pion::setImg(const char img) {
    this->img = img;
}