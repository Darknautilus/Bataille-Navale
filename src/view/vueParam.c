#include "view/VueParam.h"

#include "model/Parametre.h"
#include "model/Couleurs.h"

#include <stdio.h>

void afficherParamTest(Tparam * param)
{
	int i;
	char nomCouleur[KCOULEURS_LGNOMCOUL];

	printf("Bateaux Joueur :\n");

	printf("\n\tId\tNom\tCouleur\tType\n");
	for(i=0;i<getNbBat(param);i++)
	{
		getNom(getCouleurFromNum(param->bateauxJoueur[i].couleur), nomCouleur);
		printf("\t%d\t%s\t%s\t%d\n", i, param->bateauxJoueur[i].nomBateau, nomCouleur, getType(&(param->bateauxJoueur[i])));
	}

	printf("\nBateaux Machine :\n");

	printf("\n\tId\tNom\tCouleur\tType\n");
	for(i=0;i<getNbBat(param);i++)
	{
		getNom(getCouleurFromNum(param->bateauxJoueur[i].couleur), nomCouleur);
		printf("\t%d\t%s\t%s\t%d\n", i+getNbBat(param), param->bateauxMachine[i].nomBateau, nomCouleur, getType(&(param->bateauxMachine[i])));
	}
}
