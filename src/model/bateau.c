/**
 *   \file bateau.c
 *   \author Benoit Sauvere
 *   \date 13 mai 2012
 *   \brief Module Bateau
 *
 *   Contient le module de gestion des structure de type bateau.
*/

#include "bateau.h"
#include "parametre.h"
#include "partie.h"
#include "grille.h"

const TtypeBat tabTypesBat[KTAILLEMAXBAT] = {
    {VOILIER,"Voilier"},
    {REMORQUEUR,"Remorqueur"},
    {CARGOT,"Cargot"},
    {SOUSMARIN,"Sous-marin"},
    {PORTEAVION,"Porte-avion"}
};

const TSensBat tabSensBat[2] = {
    {HORIZONTAL,"Horizontal"},
    {VERTICAL,"Vertical"}
};

TBateau * CreerBateau()
{
	int i;
	TBateau * bat = (TBateau*) malloc(sizeof(TBateau));

    bat->estPlace = 0;

    TPosition pos;
    pos.x = 1;
    pos.y = 1;
    pos.direction = HORIZONTAL;

    bat->position = pos;

	for (i=0; i<KTAILLEMAXBAT; i++)
	{
		bat->etat[i] = INTACT;
	}

	return bat;
}

int getIdBat(TBateau * pBat)
{
	return pBat->idBateau;
}

TBateau* getBateauFromId(int idBateau){

    int nbBateauxPartie = getNbBat(globalPartie->parametres);

    //Si c'est un bateau du joueur
    if(idBateau < nbBateauxPartie) {

        //A ce stade on considère que les id sont attribué à l'image de leur index dans le tableau de bateau
        //Le bateau d'id 3 est dans la case mesBateaux[3] (on comence à 0)
        return globalPartie->joueur->mesBateaux[idBateau];

    }
    //sinon c'est un bateau de la machine
    else{

        //De même que précedemment avec une complication : les id commencent à getNbBat
        return globalPartie->machine->mesBateaux[idBateau-nbBateauxPartie];

    }

}

void toucherBateau(TBateau * bat, int posTouch)
{
	int i;

	bat->etat[posTouch] = TOUCHE;

    //Si le bateau est coule
	if (estCoule(bat))
	{
		for (i=0; i < getTypeBateau(bat); i++)
		{
			bat->etat[i] = COULE;
		}
	}
}

int nbCoupsBateau(TBateau * bat)
{
	int i;
	int nbCoups = getTypeBateau(bat);

	for (i=0; i<getTypeBateau(bat); i++)
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

    int longBateau = getTypeBateau(bat); //On récupère la longueur du bateau
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

ETypeBat getTypeBateau(TBateau *bat){
    return getType(getInfoBateau(bat->idBateau, globalPartie->parametres));
}

void setPosBat(TBateau * pBat, ESens pSens, int pAbs, int pOrd)
{
    pBat->position.direction = pSens;
    pBat->position.x = pAbs;
    pBat->position.y = pOrd;
}

int estPlacable(TBateau * bat, Grille * grille)
{
    int estPlacable = 1;
    int i;
    Coord coordCaseGrille;

    ETypeBat typeBat = getInfoBateau(bat->idBateau, partie_Param())->type;

    // dtermine si le bateau est en dehors de la grille
	if ( (bat->position.direction == HORIZONTAL && bat->position.x + (typeBat-1) > grille->NbLin) ||
        (bat->position.direction == VERTICAL && bat->position.y + (typeBat-1) > grille->NbCol) )
        estPlacable = 0;

    coordCaseGrille.noCol = 1;
    coordCaseGrille.noLin = 1;

    // dtermine si le bateau est pla sur un autre bateau
    for(i=0;i<typeBat && estPlacable;i++)
    {
        if(bat->position.direction == HORIZONTAL)
		{
			coordCaseGrille.noCol = bat->position.x + i;
			coordCaseGrille.noLin = bat->position.y;
		}
		else if(bat->position.direction == VERTICAL)
		{
			coordCaseGrille.noCol = bat->position.x;
			coordCaseGrille.noLin = bat->position.y + i;
		}

		if(Consulter(grille, coordCaseGrille)->idBateauOccupe > -1)
			estPlacable = 0;
    }

    return estPlacable;
}

void LibererBateau(TBateau * bat)
{
	free(bat);
}
