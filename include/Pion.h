//
// Created by Fatih BOZLAK on 02/11/2023.
//

#ifndef TP3_PION_H
#define TP3_PION_H

#include<iostream>

using namespace std;

class Pion {
private:
    const string label;
    const int x;
    const int y;

public:
    Pion(string label, int x, int y);

    [[nodiscard]] string getLabel() const;

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    [[nodiscard]] std::string getCoordonnees() const;
};


#endif //TP3_PION_H
