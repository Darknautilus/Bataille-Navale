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

void toucherBateau(TBateau * bat, int posTouch)
{
	int i;
	int nbTouche = 0;

	bat->etat[posTouch] = TOUCHE;

	// si l'ensemble du bateau est touché, alors il est coulé
	for (i=0; i < bat->type; i++)
	{
		if (bat->etat[i] != INTACT)
		{
			nbTouche++;
		}
	}

	if (nbTouche == bat->type)
	{
		for (i=0; i < bat->type; i++)
		{
			bat->etat[i] = COULE;
		}
	}

	//return bat;
}

/**
    Retoune le nombre de coups qu'a reçu un bateau.
    @param bat Un pointeur vers la structure du bateau
    @return Un entier.
*/
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

/**
    Retourne la postion du bateau.
    @param bat Un pointeur vers le bateau en question
    @return Une strucutre TPosition contenant les
*/
TPosition getPosBateau(TBateau * bat)
{
	return bat->position;
}


/* il faut faire égalemnt des fonctions pour les informations positionnelles direction latitude et logitude=> compléter*/
