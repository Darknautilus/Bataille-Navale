#include "model/Random.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initRandom(void)
{
    srand(time(NULL));
}

int nombreAleatoire(int pNbMin, int pNbMax)
{
    pNbMax++;
    return rand()%(pNbMax-pNbMin) + pNbMin;
}

void choixMotHasard(char * pMot, FILE * pDesc, int longMax)
{
    int nbMots = 0, numMotChoisi;
    char caractereLu;

    rewind(pDesc);

    do
    {
        caractereLu = fgetc(pDesc);
        if(caractereLu == '\n')
            nbMots++;

    }while (caractereLu != EOF);

    numMotChoisi = nombreAleatoire(1, nbMots);

    rewind(pDesc);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(pDesc);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(pMot, longMax, pDesc);
    pMot[strlen(pMot)-1] = '\0';
}
