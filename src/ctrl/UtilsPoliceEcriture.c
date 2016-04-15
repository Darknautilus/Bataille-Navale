#include "ctrl/UtilsPoliceEcriture.h"

#include "ctrl/FichierDebug.h"

#include "view/IncludeSDL.h"

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
