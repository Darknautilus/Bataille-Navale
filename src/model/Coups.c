#include "Coups.h"

Coup* CreerCoup(Joueur *joueur, Coord pos){

    Coup *coup = malloc(sizeof(Coup));

    Joueur* joueur = NULL;
    Coord pos;

    pos.noLin = 0;
    pos.noCol = 0;

    coup->carJoueur = joueur;
    coup->coordTir = pos;

    return coup;
}
