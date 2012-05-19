#include "parametre.h"

#include <stdlib.h>
#include <string.h>
#include <string.h>

//***************************
/*	N : getCouleur
	D : donne le l'index de la couleur dans la table des couleurs de couleurs.h/.c de la couleur de l'info bateau pB
	E : pB
	S :
	R : le numéro de la couleur
	Prec : -
*/

int getCouleur(const TInfoBateau * pB)
{
	return pB->couleur;
}

//***************************
/*	N : getType
	D : donne le type de l'info bateau pB
	E : pB
	S :
	R : le numéro du type
	Prec : -
*/

ETypeBat getType(const TInfoBateau * pB)
{
	return pB->type;
}


//***************************
/*	N : getNom
	D : donne nom du bateau pB
	E : pB
	S : pNom
	R :
	Prec : -
*/

void getBNom(const TInfoBateau * pB, char pNom[])
{
	strcpy(pNom,pB->nomBateau);
}

//***************************
/*	N : setInfoBateau
	D : affecte les infos pNom pCouleur et pType à l'info bateau pB
	E :  pNom pCouleur et pType
	S : pB
	R :
	Prec : -
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , ETypeBat pType)
{
	pB->couleur=pCouleur;
	pB->type=pType;
	strcpy(pB->nomBateau,pNom);
}



//***************************
/*	N : getNBInstances
	D : donne le nombre d'instances de chaque bateau pour un joueur pour les parametres de partie pParam
	E : pParam
	S :
	R : ce nombre
	Prec : -
*/
int *getNBInstances (const Tparam * pParam)
{
	return pParam->nombreInstanceBateaux;
}

int getNbInstancesType (const Tparam * pParam, ETypeBat pType)
{
	return pParam->nombreInstanceBateaux[pType-1];
}

int nbBat(const Tparam * pParam)
{
	int i;
	int nombreBat=0;
	
	for(i=0;i<K_NBTYPEBATEAUX;i++)
		nombreBat += pParam->nombreInstanceBateaux[i];

	return nombreBat;
}


//***************************
/*	N : getInfoBateau
	D : donne les information sur le pNum eme bateau des parametres de la partie
	E : pNum , pParam
	S :*
	R :  les informations sur le bateau
	Prec : le pNum eme bateau  existe
*/
TInfoBateau * getInfoBateau(int pNum ,const Tparam * pParam)
{
	TInfoBateau * infoBat;

	if (pNum < nbBat(pParam) )
		infoBat = &(pParam->bateauxJoueur[pNum]);
	else
		infoBat = &(pParam->bateauxMachine[pNum-nbBat(pParam)]);

	return infoBat;
}

//***************************
/*	N : chargerParam
	D : lit les parametres de la partie dans un descripteur de fichier pDesc
	E :pDesc
	S :pParam (pour eviter les recopies)
	R :
	Prec : pDesc est un descriteur de fichier ouvert en lecture place sur la lecture des paramètres de la partie
*/

void chargerParam(FILE * pDesc, Tparam * pParam)
{
	int nombreBat;
	
	pParam->nombreInstanceBateaux = (int*)malloc(K_NBTYPEBATEAUX * sizeof(int));
	fread(pParam->nombreInstanceBateaux, sizeof(int), K_NBTYPEBATEAUX, pDesc);
	
	nombreBat = nbBat(pParam);
	
	pParam->bateauxJoueur = (TInfoBateau*)malloc(nombreBat*sizeof(TInfoBateau));
	fread(pParam->bateauxJoueur, sizeof(TInfoBateau), nombreBat, pDesc);
	
	pParam->bateauxMachine = (TInfoBateau*)malloc(nombreBat*sizeof(TInfoBateau));
	fread(pParam->bateauxMachine, sizeof(TInfoBateau), nombreBat, pDesc); 
}

//***************************
/*	N : memParam
	D : sauve les paramètres de la partie pParam dans un fichier pDesc
	E : pDesc , pParam
	S :
	R :
	Prec : pDesc est un descriteur de fichier ouvert en écriture
*/
void memParam(const Tparam * pParam, FILE * pDesc)
{
	int nombreBat = nbBat(pParam);

	fwrite(pParam->nombreInstanceBateaux, sizeof(int), K_NBTYPEBATEAUX, pDesc);
	fwrite(pParam->bateauxJoueur, sizeof(TInfoBateau), nombreBat, pDesc);
	fwrite(pParam->bateauxMachine, sizeof(TInfoBateau), nombreBat, pDesc);
}

//***************************
/*	N : newTParam
	D : creer un Tparam pour pNbInstances de chaque bateau pour chacun : remarque devra allouer les tableaux dynamiques
	E :pNbInstances,
	S : pP
	R :
	Prec : -
*/
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
    
	nb = K_NBTYPEBATEAUX*pNbInstances;
	param->bateauxJoueur = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
	param->bateauxMachine = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
	
    return param;
}



//***************************
/*	N : setIemeInfoBateauTParam
	D : COMPLETER
	E  pIdBateau  pNom[] pCouleur  pType
	S : pParam
	R :
	Prec : ne peut etre appelé qu'apres newTParam
*/

void setIemeInfoBateauTParam(int pIdBateau , Tparam * pParam,const char pNom[], int pCouleur , ETypeBat pType)
{

	if (pIdBateau<nbBat(pParam))
	{
		pParam->bateauxJoueur[pIdBateau].couleur=pCouleur;
		pParam->bateauxJoueur[pIdBateau].type=pType;
		strcpy(pParam->bateauxJoueur[pIdBateau].nomBateau ,pNom);
	}

	else
	{
		pParam->bateauxMachine[pIdBateau-nbBat(pParam)].couleur=pCouleur;
		pParam->bateauxMachine[pIdBateau-nbBat(pParam)].type=pType;
		strcpy(pParam->bateauxMachine[pIdBateau-nbBat(pParam)].nomBateau, pNom);
	}

}









