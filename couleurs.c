

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "couleurs.h"

const Couleur tableCouleurs[KCOULEURS_NBCOULMAX] = {
	{'F',"FUSHIA", MAGENTA} ,
	{'R',"ROUGE", RED},
	{'B', "BLEU", BLUE},
	{'C', "CYAN",CYAN },
	{'M',"MARRON",BROWN},
	{'J', "JAUNE" ,YELLOW},
	{'V',"VERT", GREEN}
} ;

int couleurs_nbCouleurs (void)
{
     return KCOULEURS_NBCOULMAX ;
}

Couleur lettreToCouleur (char pLettre  )
{
    int i;
    for (i=0;i<couleurs_nbCouleurs ();i++)
        if (tableCouleurs[i].lettre == pLettre) return tableCouleurs[i];
    return tableCouleurs[0]; // impossible mettre une precondition lettre existe
}

Couleur getCouleurFromNum (int pI)
{
    return tableCouleurs[pI];
}


COLORS getColor (Couleur pCouleur)
{
    return pCouleur.num;
}

char getChar (Couleur pCouleur)
{
    return pCouleur.lettre;
}
void getNom (Couleur pCouleur, char pNom[])
{
    strcpy(pNom,pCouleur.nom);
}



