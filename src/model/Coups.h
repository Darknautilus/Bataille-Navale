#ifndef COUPS_H
#define COUPS_H

#include "joueur.h"

typedef struct
{
	Joueur *carJoueur;
	Coord coordTir;
}Coup;

Coup* CreerCoup(Joueur *joueur, Coord pos);

#endif
