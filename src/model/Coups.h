#ifndef COUPS_H
#define COUPS_H

typedef struct
{
	Joueur *carJoueur;
	Coord coordTir;
}Coup;

Coup* CreerCoup(Joueur *joueur, Coord pos);

#endif
