#include "Grille.h"
#include "Humain.h"
#include "Ia.h"
#include "Morpion.h"
#include "Pion.h"
#include <iostream>
using namespace std;
int main() {
    std::shared_ptr<Jeux> j = std::make_shared<Morpion>("Fatih");

    j->demarrerPartie();


    return 0;
}
