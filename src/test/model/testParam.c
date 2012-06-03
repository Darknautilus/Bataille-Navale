#include "testParam.h"

#include "vueParam.h"

void controleurParametreVersionTest(Tparam *param)
{
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
	Tparam * param = newTParam(1);
	Tparam * paramLu = newTParam(1);
	FILE * ficParam;

	printf("\n\nAjout des bateaux\n");
	controleurParametreVersionTest(param);
	printf("Fait\n");

	printf("\nAffichage des bateaux\n");
	AfficherParamTest(param);
	printf("Fait\n");

	printf("\nEnregistrement dans un fichier\n");
	ficParam = fopen("param.txt", "w");
	memParam(param, ficParam);
	fclose(ficParam);
	printf("Fait\n");

	printf("\nLecture fichier paramètres\n");
	ficParam = fopen("param.txt", "r");
	chargerParam(ficParam, paramLu);
	fclose(ficParam);
	printf("Fait\n");

	printf("\nAffichage des parametres lus\n");
	AfficherParamTest(paramLu);
	printf("Fait\n");

}
