/**
 *   \file utilsPoliceEcriture.h
 *   \author Benoit Sauvere
 *   \date 03 juin 2012
 *   \brief Module Utillitaire Police Ecriture
 *
 *   Contient les d�clarations pour le module des utilitaires de chargement des polices d'�criture.
*/

#ifndef UTILSFONT_H
#define UTILSFONT_H

#include "../view/includeSDL.h"

/**
    Charge une police d'�criture contenue dans le fichier des polices d'�criture
    \param pChemin Le chemin de la police dans le dossier contenant les polices d'�critures
    \param pTailleEcriture Un entier contenant la taille de la police.
    \return Une structure TTF_Font contenant la police charg�e.
*/
TTF_Font * chargerPoliceEcriture(const char pChemin[], int pTailleEcriture);

#endif
