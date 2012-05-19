#include <stdio.h>

#include "test.h"
#include "parametre.h"

void MenuTest(void)
{
	int choixMenu;
	int continuer = 1;
	
	while (continuer)
	{
		printf("\n\n== Module de tests ==\n\n");
	
		printf("1 - Parametres\n");
		printf("0 - Quitter\n");
	
		printf("Choix =>");
		scanf("%d", &choixMenu);
	
		switch (choixMenu)
		{
			case 0:
				continuer = 0;
				break;
				
			case 1:
				TestParam();
				break;
			
			default:
				printf("Erreur, veuillez reessayer");
				break;
		}
	}
}

void controleurParametreVersionTest(Tparam *param)
{
	param = newTParam(1);
	
	// boucles avec void newTParam(int pIdBateau , Tparam * pP, char pNom[], int pCouleur , EType pType) doit remplacer ce qui suit
	setIemeInfoBateauTParam(0 , param, "redon", 0 , VOILIER);
	setIemeInfoBateauTParam(1 , param, "peninou", 1 , REMORQUEUR);
	setIemeInfoBateauTParam(2 , param, "canut", 2 , PORTEAVION);
	setIemeInfoBateauTParam(3, param , "caplain", 3 , SOUSMARIN);
	setIemeInfoBateauTParam(4 , param , "bruel", 4 , CARGOT);
	setIemeInfoBateauTParam(5 , param , "inglebert", 5 , VOILIER);
	setIemeInfoBateauTParam(6 , param , "verdier", 0 , REMORQUEUR);
	setIemeInfoBateauTParam(7 , param , "nonne", 1 , PORTEAVION);
	setIemeInfoBateauTParam(8, param, "bertron", 3, SOUSMARIN);
	setIemeInfoBateauTParam(9, param, "sauvere", 2, CARGOT);
}

void TestParam(void)
{
	Tparam * param;
	
	controleurParametreVersionTest(param);
}