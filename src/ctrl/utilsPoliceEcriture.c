/**
 *   \file utilsPoliceEcriture.c
 *   \author Benoit Sauvere
 *   \date 03 juin 2012
 *   \brief Module Utillitaire Police Ecriture
 *
 *   Contient les implémentations pour le module des utilitaires de chargement des polices d'écriture.
*/

#include "utilsPoliceEcriture.h"

#include "../view/includeSDL.h"

#include "../ctrl/fichierDebug.h"

#include <stdlib.h>
#include <string.h>

TTF_Font * chargerPoliceEcriture(const char * pChemin, int pTailleEcriture)
{
    TTF_Font * police;
    char * chemin = (char*)malloc(sizeof(char)*(strlen(pChemin) + strlen(FONT_REP)));

    strcpy(chemin, FONT_REP);
    strcat(chemin, pChemin);
    
    police = TTF_OpenFont(chemin, pTailleEcriture);
    free(chemin);
    
    return police;
}
