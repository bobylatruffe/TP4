//
// Created by Fatih BOZLAK on 02/11/2023.
//

#include "Pion.h"

Pion::Pion(string label, const int x, const int y) : label(label), x(x), y(y) {}

string Pion::getLabel() const {
    return this->label;
}

int Pion::getX() const {
    return this->x;
}

int Pion::getY() const {
    return this->y;
}

std::string Pion::getCoordonnees() const {
    return "x: " + std::to_string(getX()) + " y: " + std::to_string(getY());
}
