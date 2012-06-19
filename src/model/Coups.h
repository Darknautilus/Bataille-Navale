#ifndef COUPS_H
#define COUPS_H

#include "joueur.h"

typedef struct
{
	ETypeJoueur type;
	Coord coordTir;
}Coup;

/**
 * Créer une structure contenant les informations sur un tir.
 * \param[in] estJoueur 1 = tir du joueur, sinon tir de la machine
 * \param[in] pos Les coordonnées du tir.
 * \return Un pointeur sur le coups crée.
**/
Coup* CreerCoup(int estJoueur, Coord pos);


#endif
