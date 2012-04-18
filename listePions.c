#include "listePions.h"
#include "util.h"


//***************************
/*	N : creerVide
	D : cree une liste vide de pions
	E :
	S :
	R : liste de pions
	Prec : -
*/

TlistePions creerVide(void)
{
    TlistePions l;
        int i,j;
        for (i=0;i<K_NBCOULEURS;i++)
            for (j=0;j<K_NBFORMES;j++)
                l.contenu [i][j]=0;
    return l;
}


//***************************
/*	N : creerPioche
	D : cree une liste de pions avec pions avec tous les pions
	E :
	S :
	R : liste de pions
	Prec : -
*/

TlistePions creerPioche(void)
{
    TlistePions l;
        int i,j;
        for (i=0;i<K_NBCOULEURS;i++)
            for (j=0;j<K_NBFORMES;j++)
                l.contenu [i][j]=K_NBPIONCHAQUETYPE;
    return l;
}



//***************************
/*	N : addPion
	D : ajoute le pion pP à la liste pL
	E : pP pL
	S : pL
	R : la nouvelle liste
	Prec : -
*/

TlistePions * addPion(Tpion pP, TlistePions * pL)
{
    pL->contenu[getCouleur( pP)][getForme( pP)]++;
    return pL;
}


//***************************
/*	N : remPion
	D : supprime le pion pP à la liste pL
	E : pP pL
	S : pL
	R : la nouvelle liste
	Prec : le pion est dans la liste
*/

TlistePions * remPion(Tpion pP, TlistePions * pL)
{
    pL->contenu[getCouleur( pP)][getForme( pP)]--;
    return pL;
}

//***************************
/*	N : existePion
	D : teste si le pion pP est dans la liste pL
	E : pP pL
	S :
	R : est présent ou pas
	Prec :
*/

int existePion(Tpion pP, TlistePions * pL)
{
    return pL->contenu[getCouleur( pP)][getForme( pP)]>0;
}

//***************************
/*	N : piocher
	D : pioche pNbPions ou le nombre de pions restant dans la pioche dans la pioche pLPioche et les met dans pLJoueur
	E :pLPioche pLJoueur pNbPions
	S : pLPioche pLJoueur
	R : _
	Prec :  pNbPions > 0 et pioche non vide
*/

void piocher(TlistePions * pLPioche, TlistePions * pLJoueur, int pNbPions)
{
    int trouve,i;
    int numC,numF;
    Tpion pion;


    for (i=0;i<pNbPions;i++)
    {
        trouve = 0;
        while(!trouve)
        {
            numC =  ( rand() % K_NBCOULEURS )  ;
            numF =  ( rand() % K_NBFORMES )  ;
            if (pLPioche ->contenu[numC][numF ]>0)
            {
                pion.mCouleur = numC;
                pion.mForme = numF;
                pLJoueur = addPion(pion , pLJoueur);
                pLPioche = remPion(pion, pLPioche);
                trouve =1;
            }

        }
    }
}




//***************************
/*	N : estVide
	D : teste si la liste est vide
	E :pLP
	S :
	R : est présent ou pas
	Prec :
*/

int estVide(TlistePions * pL)
{

        int i,j;
        for (i=0;i<K_NBCOULEURS;i++)
            for (j=0;j<K_NBFORMES;j++)
                if (pL->contenu [i][j]!=0) return 0;
    return 1;
}




