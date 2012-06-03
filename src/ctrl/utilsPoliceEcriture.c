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

TTF_Font SDLCALL* chargerPoliceEcriture(const char pChemin[], int pTailleEcriture){

    char * chemin = malloc(sizeof(FONT_REP) + sizeof(char)*strlen(pChemin));

    strcpy(chemin, FONT_REP);
    strcat(chemin, pChemin);

    return TTF_OpenFont(chemin, pTailleEcriture);
}
