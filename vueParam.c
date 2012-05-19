#include <stdio.h>

#include "vueParam.h"
#include "parametre.h"
#include "couleurs.h"

void AfficherParamTest(Tparam * param)
{
	int i;
	char nomCouleur[KCOULEURS_LGNOMCOUL];
	
	printf("Bateaux Joueur :\n");
	
	printf("\n\tId\tNom\tCouleur\tType\n");
	for(i=0;i<nbBat(param);i++)
	{
		getNom(getCouleurFromNum(getCouleur(&(param->bateauxJoueur[i]))), nomCouleur);
		printf("\t%d\t%s\t%s\t%d\n", i, param->bateauxJoueur[i].nomBateau, nomCouleur, getType(&(param->bateauxJoueur[i])));
	}
	
	printf("\nBateaux Machine :\n");
	
	printf("\n\tId\tNom\tCouleur\tType\n");
	for(i=0;i<nbBat(param);i++)
	{
		getNom(getCouleurFromNum(getCouleur(&(param->bateauxMachine[i]))), nomCouleur);
		printf("\t%d\t%s\t%s\t%d\n", i+nbBat(param), param->bateauxMachine[i].nomBateau, nomCouleur, getType(&(param->bateauxMachine[i])));
	}
}