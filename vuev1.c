#include "vuev1.h"

// pour les couleurs

//***************************
/*	N : afficherCouleur
	D :  affiche le nom de la couleur d'index i
	E : pB
	S :
	R :  -
	Prec : -


*/
void afficherCouleur(int pI)
{
    char nom[KCOULEURS_LGNOMCOUL+1];
    getNom (getCouleurFromNum ( pI), nom);
    printf("Couleur : %s\t", nom);
}


// pour les types

//***************************
/*	N : afficherType
	D :  affiche le nom de la type de bateau d'index i
	E : pB
	S :
	R :  -
	Prec : -


*/
void afficherType(int pI)
{
    switch(pI)
    {
        case remorqueur: printf("remorqueur\t");break;
        case porteAvion: printf("porteAvion\t");break;
        case sousMarin: printf("sousMarin\t");break;
        case cargot: printf("cargot\t");break;
        default:break;
    }
}
// Pour le bateau
//***************************
/*	N : afficherInfoBateau
	D :  affiche les  Informations sur à l'info bateau pB
	E : pB
	S :
	R :  -
	Prec : -


*/
void afficherInfoBateau(const TInfoBateau *pB)
{
    afficherCouleur(pB->mCouleur);
    afficherType(pB->mType );
    printf("Nom : %s\n",pB->mNom);
}


//***************************
/*	N : afficherBateau
	D :  affiche les  Informations sur un bateau pB
	E : pB, pParam
	S :
	R :  -
	Prec : -


*/
void afficherBateau(const TBateau *pB,const Tparam * pParam)
{
    afficherInfoBateau(getInfoBateau(pB->idInfoBateau, pParam));


    //COMPLETER
}


//***************************
/*	N : afficherParam
	D :  affiche les  param
	E : param
	S :
	R :  -
	Prec : -
*/


void afficherParam(const Tparam * pParam)
{
    int i;
    int nb = K_NBTYPEBATEAUX*getNBInstances (pParam);
    printf("Nombre d'instances %d\n", pParam->mNombreInstanceBateaux);

    for (i=0;i<nb;i++) afficherInfoBateau (&(pParam->mBateauxDuJoueur[i]));

    for (i=0;i<nb;i++) afficherInfoBateau (&(pParam->mBateauxMachine [i]));

}

//***************************
/*	N : saisirInfoBateau
	D : ...
	E :
	S : ...
	R :  -
	Prec : -
*/

void saisirInfoBateau(TInfoBateau *pB)
{
    //COMPETER
    //pour test uniquement

}




