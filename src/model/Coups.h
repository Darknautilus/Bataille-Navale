/**
 * \file Coups.h
 * \author Benoît Sauvère
 * \date 19 juin 2012
 * \brief Modèle Coup
 *
 * Contient les déclarations du module Coup, représentant un coup d'un joueur.
*/

#ifndef COUPS_H
#define COUPS_H

#include "../model/Joueur.h"

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
Coup* creerCoup(int estJoueur, Coord pos);


#endif
