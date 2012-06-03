/**
 * \file parametre.c
 * \author Aurélien Bertron
 * \date 19 mai 2012
 * \brief Module Paramètres
 *
 * Le module parametre d'une partie permet de charger et sauver ces paramètres dans un fichier.
 */

#include "parametre.h"

#include <stdlib.h>
#include <string.h>
#include <string.h>

#include "bateau.h"

//int idDernierBateau = 0;/**< \brief Continent le dernier ID attribuÈ.*/

//***************************

int getCouleur(const TInfoBateau * pB)
{
	return pB->couleur;
}

//***************************

ETypeBat getType(const TInfoBateau * pB)
{
	return pB->type;
}


//***************************

void getBNom(const TInfoBateau * pB, char pNom[])
{
	strcpy(pNom,pB->nomBateau);
}

//***************************

void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , ETypeBat pType)
{
	pB->couleur=pCouleur;
	pB->type=pType;
	strcpy(pB->nomBateau,pNom);
}



//***************************

Tparam * newTParam(int pNbInstances)
{
	int nb;
    int i;
    Tparam * param = (Tparam*)malloc(sizeof(Tparam));

	param->nombreInstanceBateaux=(int*)malloc(K_NBTYPEBATEAUX * sizeof(int));
    for(i=0;i<K_NBTYPEBATEAUX;i++)
    {
        param->nombreInstanceBateaux[i] = pNbInstances;
    }

	nb = getNbBat(param);
	param->bateauxJoueur = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
	param->bateauxMachine = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));

    return param;
}

//***************************

int *getNBInstances (const Tparam * pParam)
{
	return pParam->nombreInstanceBateaux;
}

//***************************

int getNbInstancesType (const Tparam * pParam, ETypeBat pType)
{
	return pParam->nombreInstanceBateaux[pType-1];
}

//***************************

int getNbBat(const Tparam * pParam)
{
	int i;
	int nombreBat=0;

	for(i=0;i<K_NBTYPEBATEAUX;i++)
		nombreBat += pParam->nombreInstanceBateaux[i];

	return nombreBat;
}

//***************************

TInfoBateau * getInfoBateau(int pNum ,const Tparam * pParam)
{
	TInfoBateau * infoBat;

	if (pNum < getNbBat(pParam) )
		infoBat = &(pParam->bateauxJoueur[pNum]);
	else
		infoBat = &(pParam->bateauxMachine[pNum-getNbBat(pParam)]);

	return infoBat;
}



//***************************

void chargerParam(FILE * pDesc, Tparam * pParam)
{
	int nombreBat;

	fread(pParam->nombreInstanceBateaux, sizeof(int), K_NBTYPEBATEAUX, pDesc);

	nombreBat = getNbBat(pParam);

	fread(pParam->bateauxJoueur, sizeof(TInfoBateau), nombreBat, pDesc);

	fread(pParam->bateauxMachine, sizeof(TInfoBateau), nombreBat, pDesc);
}

//***************************

void memParam(const Tparam * pParam, FILE * pDesc)
{
	int nombreBat = getNbBat(pParam);

	fwrite(pParam->nombreInstanceBateaux, sizeof(int), K_NBTYPEBATEAUX, pDesc);

	fwrite(pParam->bateauxJoueur, sizeof(TInfoBateau), nombreBat, pDesc);

	fwrite(pParam->bateauxMachine, sizeof(TInfoBateau), nombreBat, pDesc);
}

//***************************

void setIemeInfoBateauTParam(int pIdBateau , Tparam * pParam,const char pNom[], int pCouleur , ETypeBat pType)
{

    //Si l'id du bateau est infÈrieure au nombre de bateaux par joueur
    //C'est un bateau du joueur
	if (pIdBateau<getNbBat(pParam))
	{
		pParam->bateauxJoueur[pIdBateau].couleur=pCouleur;
		pParam->bateauxJoueur[pIdBateau].type=pType;
		strcpy(pParam->bateauxJoueur[pIdBateau].nomBateau ,pNom);
	}

    //Sinon c'est un batea de l'IA
	else
	{
		pParam->bateauxMachine[pIdBateau-getNbBat(pParam)].couleur=pCouleur;
		pParam->bateauxMachine[pIdBateau-getNbBat(pParam)].type=pType;
		strcpy(pParam->bateauxMachine[pIdBateau-getNbBat(pParam)].nomBateau, pNom);
	}

}









