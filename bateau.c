/**
 *   \file bateau.c
 *   \author Benoit Sauvere
 *   \date 13 mai 2012
 *   \brief Module Bateau
 *
 *   Contient le module de gestion des structure de type bateau.
*/

#include <stdlib.h>

#include "bateau.h"
#include "parametre.h"

TBateau * creerBateau(TPosition pos, ETypeBat type)
{
	int i;
	TBateau * bat = (TBateau*) malloc(sizeof(TBateau));

	bat->position = pos;
	bat->type = type;

	for (i=0; i<type; i++)
	{
		bat->etat[i] = INTACT;
	}

	return bat;
}

int getIdBat(TBateau * pBat)
{
	return pBat->idBateau;
}

void toucherBateau(TBateau * bat, int posTouch)
{
	int i;

	bat->etat[posTouch-1] = TOUCHE;

    //Si le bateau est coule
	if (estCoule(bat))
	{
		for (i=0; i < bat->type; i++)
		{
			bat->etat[i] = COULE;
		}
	}

}

int nbCoupsBateau(TBateau * bat)
{
	int i;
	int nbCoups = bat->type;

	for (i=0; i<bat->type; i++)
	{
		if (bat->etat[i] != INTACT)
			nbCoups--;
	}

	return nbCoups;
}

TPosition getPosBateau(TBateau * bat)
{
	return bat->position;
}

int estCoule(TBateau * bat){

    int longBateau = bat->type; //On récupère la longueur du bateau
    int i = 0;

    int resultat = 1; //Par défaut non coulé

    //Tant que l'on a pas trouvé une case non touchée et que la longueur du bateau n'est pas dépassée
    while(resultat != 0 && i < longBateau){

        //Si un case n'est pas touchée
        if(bat->etat[i] == INTACT){
            //Le bateau n'est pas coulé
            resultat = 0;
        }

        i++;
    }

    return resultat;
}

int getPosXBateau(TBateau *bat){
    return bat->position.x;
}

int getPosYBateau(TBateau *bat){
    return bat->position.y;
}

ESens getSensBateau(TBateau *bat){
    return bat->position.direction;
}
