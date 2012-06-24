#include "Coups.h"
#include "Joueur.h"

#include <stdlib.h>

Coup* creerCoup(int estJoueur, Coord pos){

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
