// Permet la portabilité du programme
#ifdef __APPLE__
	#include <SDL/SDL.h>
#else
	#include <SDL/SDL.h>
#endif

#include <string.h>

#include "couleurs.h"

const Couleur tableCouleurs[KCOULEURS_NBCOULMAX] = {
	{'F',"FUSHIA", {255,0,255} } ,
	{'R',"ROUGE", {255,0,0} },
	{'B', "BLEU", {0,0,255} },
	{'C', "CYAN", {0,255,255} },
	{'M',"MARRON", {91,59,17} },
	{'J', "JAUNE" , {255,255,0} },
	{'V',"VERT", {0,255,0} }
} ;

// à quoi ça sert?
// pourquoi elle s'appelle pas getNbCouleurs?
int nbCouleurs (void)
{
	return KCOULEURS_NBCOULMAX ;
}

// modifié car il y avait un return conditionnel, mon compilo n'en veut pas (et c'est moche :p )
Couleur lettreToCouleur (char pLettre  )
{
	int i = 0;

	while (i < nbCouleurs() && tableCouleurs[i].lettre != pLettre)
	{
		i++;
	}

	return tableCouleurs[i];
}

Couleur getCouleurFromNum (int pI)
{
	return tableCouleurs[pI];
}


SDL_Color getColor (Couleur * pCouleur)
{
	return pCouleur->rgb;
}

char getChar (Couleur * pCouleur)
{
	return pCouleur->lettre;
}

void getNom (Couleur * pCouleur, char pNom[])
{
	strcpy(pNom,pCouleur->nom);
}



