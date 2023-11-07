#include "Grille.h"
#include "Humain.h"
#include "Ia.h"
#include "Morpion.h"
#include "Pion.h"
#include "Puissance4.h"
#include <iostream>
using namespace std;
int main() {
    while (true) {
        int jeuxChoisi = 0;
        std::cout << "1 Morpion" << std::endl;
        std::cout << "2 Puissance 4" << std::endl;
        std::cout << "3 Quitter" << std::endl;
        std::cout << "Quel jeux ? ";

        std::cin >> jeuxChoisi;

        switch (jeuxChoisi) {
            case 1:
                Morpion("Fatih").demarrerPartie();
                break;

            case 2:
                Puissance4("Fatih").demarrerPartie();
                break;

            case 3:
                return 0;
        }
    }
}