//
// Created by Fatih BOZLAK on 07/11/2023.
//

#ifndef TP3_PUISSANCE4_H
#define TP3_PUISSANCE4_H
#include "Grille.h"
#include "Jeux.h"
#include "Joueur.h"
#include <memory>
#include <vector>
class Puissance4 : public Jeux {

public:
    Puissance4(std::string pseudo);

private:
    std::shared_ptr<Joueur> checkAlignement();

    std::shared_ptr<Joueur> checkVainqueur() override;
    void demanderAJoueurDeJouer(std::shared_ptr<Joueur> joueur) override;
    bool estNulle() override;
};
#endif//TP3_PUISSANCE4_H
