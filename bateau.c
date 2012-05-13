/**
 *   @file bateau.c
 *   @author Benoit Sauvere
 *   @date 13/05/2012
 *   @brief Module Bateau
 *
 *   Contient le module de gestion des structure de type bateau.
*/

#include "bateau.h"
#include "parametre.h"

/**
    Créer un bateau.
    @param pos La position du bateau
    @param type Le type du bateau
    @return Une strucutre Bateau correctement initialisée.
*/
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

/**
    Cette fonction marque une case d'un bateau donnée comme touchée.
    @param bat Le pointeur sur le bateau en question
    @param posTouch La postion touchée.
    @return
*/
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

/**
    Vérifie si le bateau est coulé.
    @param bat Un pointeur sur une structure TBateau
    @return 1 si le bateau est coulé, 0 si il est en vie
*/
int estCoule(TBateau * bat){

    int longBateau = bat->type; //On récupère la longueur du bateau
    int i = 0;

    int resultat = 1; //Par défaut non coulé

    //Tant que l'on a pas trouvé une case non touchée et que la longueur du bateau n'est pas dépassée
    while(resultat != 0 && i < longBateau){

        //Si un case n'est pas touchée
        if(bat->etat[i] == 0){
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




