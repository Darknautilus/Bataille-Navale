#include "ctrl/UtilsModel.h"

#include "view/IncludeSDL.h"

#include "ctrl/FichierDebug.h"

#include <string.h>
#include <stdio.h>

FILE * ouvrirFichierRessources(const char * nomFic, const char * mode)
{
    char mesErreur[50];
    FILE * descFic;
    char * chemin = (char*)malloc(sizeof(RESSOURCES_REP)+strlen(nomFic)*sizeof(char));

    strcpy(chemin, RESSOURCES_REP);
    strcat(chemin, nomFic);

    descFic = fopen(chemin, mode);
    if(descFic == NULL)
    {
        strcpy(mesErreur, nomFic);
        strcat(mesErreur, " n'a pas pu être chargé.");
        dgErreur(mesErreur);
        exit(EXIT_FAILURE);
    }

    return descFic;
}
