#include <stdio.h>

#include "test.h"
//#include "testParam.h"
#include "../model/parametre.h"

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
				//TestParam();
				break;

			default:
				printf("Erreur, veuillez reessayer");
				break;
		}
	}
}

