//
// Created by Fatih BOZLAK on 04/11/2023.
//

#include "Humain.h"

Humain::Humain(std::string pseudo) : Joueur(pseudo, TypeDeJoueur::HUMAIN_PLAYER) {}

std::shared_ptr<Pion> Humain::jouer(vector<std::shared_ptr<Pion>> &pionsPossibles) {
    int pionChoisiParJoueur = 0;
    while (pionChoisiParJoueur < 1 || pionChoisiParJoueur > pionsPossibles.size()) {
        std::cout << "Voici les emplacements possibles : " << std::endl;

        int i = 1;
        for (const shared_ptr<Pion> &pion: pionsPossibles) {
            std::cout << "Pion " << i++ << " : " << pion->getCoordonnees() << std::endl;
        }

        std::cout << "Donner le numéro du pion que vous voulez jouer : ";
        std::cin >> pionChoisiParJoueur;
        //TODO Vérifier l'entrée du joueur !
    }

    return pionsPossibles[pionChoisiParJoueur];
}