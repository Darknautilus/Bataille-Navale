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
    return pB->mCouleur;
}

//***************************
/*	N : getType
	D : donne le type de l'info bateau pB
	E : pB
	S :
	R : le numéro du type
	Prec : -
*/

EType getType(const TInfoBateau * pB)
{
    return pB->mType;
}


//***************************
/*	N : getNom
	D : donne nom du bateau pB
	E : pB
	S : pNom
	R :
	Prec : -
*/

void getBNom(const TInfoBateau * pB, char pNom[]) //voir tp sur les chaines de caractères dynamique*/
{
    strcpy(pNom,pB->mNom);
}

//***************************
/*	N : setInfoBateau
	D : affecte les infos pNom pCouleur et pType à l'info bateau pB
	E :  pNom pCouleur et pType
	S : pB
	R :
	Prec : -
*/
void setInfoBateau (TInfoBateau *pB, char pNom[], int pCouleur , EType pType)
{
    pB->mCouleur=pCouleur;
    pB->mType=pType;
    strcpy(pB->mNom,pNom);
}



//***************************
/*	N : getNBInstances
	D : donne le nombre d'instances de chaque bateau pour un joueur pour les parametres de partie pParam
	E : pParam
	S :
	R : ce nombre
	Prec : -
*/
int getNBInstances (const Tparam * pParam)
{
    return pParam->mNombreInstanceBateaux;
}



//***************************
/*	N : getInfoBateau
	D : donne les information sur le pNum eme bateau des parametres de la partie
	E : pNum , pParam
	S :*
	R :  les informations sur le bateau
	Prec : le pNum eme bateau  existe
*/

TInfoBateau *getInfoBateau(int pNum ,const Tparam * pParam)
{
    if (pNum<K_NBTYPEBATEAUX*getNBInstances (pParam))
        return &(pParam->mBateauxDuJoueur[pNum]);
    return &(pParam->mBateauxMachine[pNum-K_NBTYPEBATEAUX*getNBInstances (pParam)]);
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
   /* Tparam param; pour eviter recopie*/
    int nb;
    fread (&(pParam->mNombreInstanceBateaux), sizeof(int), 1, pDesc);
    nb = K_NBTYPEBATEAUX*getNBInstances (pParam);
    pParam->mBateauxDuJoueur = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
    pParam->mBateauxMachine = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
    fread ((pParam->mBateauxDuJoueur), sizeof(TInfoBateau), nb, pDesc);
    fread ((pParam->mBateauxMachine), sizeof(TInfoBateau), nb, pDesc);
   /* return param;*/
}

//***************************
/*	N : memParam
	D : sauve les paramètres de la partie pParam dans un fichier de nom pNom
	E :pNom , pParam
	S :
	R :
	Prec : pDesc est un descriteur de fichier ouvert en écriture
*/

void memParam(const Tparam * pParam, FILE * pDesc)
{
    int nb = K_NBTYPEBATEAUX*getNBInstances (pParam);
    int i;
    fwrite (&(pParam->mNombreInstanceBateaux), sizeof(int), 1, pDesc);
    for (i=0;i<nb;i++) fwrite (&(pParam->mBateauxDuJoueur[i]), sizeof(TInfoBateau), 1, pDesc);
    for (i=0;i<nb;i++) fwrite  (&(pParam->mBateauxMachine[i]), sizeof(TInfoBateau), 1, pDesc);
}


//***************************
/*	N : newTParam
	D : creer un Tparam pour pNbInstances de chaque bateau pour chacun : remarque devra allouer les tableaux dynamiques
	E :pNbInstances,
	S : pP
	R :
	Prec : -
*/
void newTParam(int pNbInstances , Tparam * pP)
/* question a ce poser les tableaux sont vides qui doit faire les saisies des informations sur les bateaux : la vue, le contrôleur va donc appeler la vue
pour saisir les info sur un bateau puis appeler un fonction du module param pour initialiser le nième bateau de la liste des paramètres =>

*/

{
   /* Tparam param; pour eviter recopie*/
    int nb;
    pP->mNombreInstanceBateaux=pNbInstances;
    nb = K_NBTYPEBATEAUX*getNBInstances (pP);
    pP->mBateauxDuJoueur = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
    pP->mBateauxMachine = (TInfoBateau * )malloc(nb * sizeof(TInfoBateau));
   /* return param;*/
}




//***************************
/*	N : setIemeInfoBateauTParam
	D : COMPLETER
	E  pIdBateau  pNom[] pCouleur  pType
	S : pParam
	R :
	Prec : ne peut etre appelé qu'apres newTParam
*/

void setIemeInfoBateauTParam(int pIdBateau , Tparam * pParam,const char pNom[], int pCouleur , EType pType)
{

    if (pIdBateau<K_NBTYPEBATEAUX*getNBInstances (pParam))
    {
        pParam->mBateauxDuJoueur[pIdBateau].mCouleur=pCouleur;
        pParam->mBateauxDuJoueur[pIdBateau].mType=pType;
        strcpy(pParam->mBateauxDuJoueur[pIdBateau].mNom ,pNom);
    }
    else
    {
        pParam->mBateauxMachine[pIdBateau-K_NBTYPEBATEAUX*getNBInstances (pParam)].mCouleur=pCouleur;
        pParam->mBateauxMachine[pIdBateau-K_NBTYPEBATEAUX*getNBInstances (pParam)].mType=pType;
        strcpy(pParam->mBateauxMachine[pIdBateau-K_NBTYPEBATEAUX*getNBInstances (pParam)].mNom, pNom);
    }

}












