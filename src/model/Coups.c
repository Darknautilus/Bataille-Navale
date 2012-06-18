#include "Coups.h"
#include "joueur.h"

#include <stdlib.h>

Coup* CreerCoup(Joueur *joueur, Coord pos){

    Coup *coup = malloc(sizeof(Coup));

    coup->carJoueur = joueur;
    coup->coordTir = pos;

    return coup;
}
