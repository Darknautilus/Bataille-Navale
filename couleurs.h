#ifndef _COULEURS_H
#define _COULEURS_H

#ifdef __APPLE__
	#include <SDL/SDL.h>
#else
	#include <SDL.h>
#endif

#define KCOULEURS_NBCOULMAX 7
#define KCOULEURS_LGNOMCOUL 10

typedef
	struct
	{
		char lettre;
		char nom[KCOULEURS_LGNOMCOUL+1];
		SDL_Color rgb;
	}
Couleur;

int nbCouleurs (void);

/*
    Retourne la couleur correspondant à la lettre entrée.

    lettre doit exister dans le tableau de couleurs
*/
Couleur lettreToCouleur (char pLettre);

/*
    Retourne la couleur associée à l'indice pI dans le tableau des couleurs.

    Le tableau doit avoir au moins pI+1 éléments
*/
Couleur getCouleurFromNum (int pI);

// fonction d'accès à chacun des champs de la structure couleur
SDL_Color getColor (Couleur * pCouleur);
char getChar (Couleur * pCouleur);
void getNom (Couleur * pCouleur, char pNom[]);

#endif

