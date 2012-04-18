#ifndef _COULEURS_H
#define _COULEURS_H

#include "coniocouleur.h"


#define KCOULEURS_NBCOULMAX 7
#define KCOULEURS_LGNOMCOUL 10

typedef
	struct
	{
		char lettre;
		char nom[KCOULEURS_LGNOMCOUL+1];
		COLORS  num;
	}
Couleur;

//   mettre une precondition lettre existe retourne la couleur associée à la lettre
Couleur lettreToCouleur (char pLettre);
//   mettre une precondition ...[pI] défini
//retourne la couleur à l'indice pI dans le tableau des couleurs  tableCouleurs
Couleur getCouleurFromNum (int pI);

// fonction d'accès à chacun des champs de la structure couleur
COLORS getColor (Couleur pCouleur);
char getChar (Couleur pCouleur);
void getNom (Couleur pCouleur, char pNom[]);

#endif

