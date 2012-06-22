#include "Coups.h"
#include "Joueur.h"

#include <stdlib.h>

Coup* CreerCoup(int estJoueur, Coord pos){

    Coup *coup = malloc(sizeof(Coup));

    if(estJoueur){
        coup->type = HUMAIN;
    }
    else{
        coup->type = MACHINE;
    }

    coup->coordTir = pos;

    return coup;
}
