/**
 *   \file utilsPoliceEcriture.h
 *   \author Benoit Sauvere
 *   \date 03 juin 2012
 *   \brief Module Utillitaire Police Ecriture
 *
 *   Contient les déclarations pour le module des utilitaires de chargement des polices d'écriture.
*/

#ifndef UTILSFONT_H
#define UTILSFONT_H

#include "../view/includeSDL.h"

/**
    Charge une police d'écriture contenue dans le fichier des polices d'écriture
    \param pChemin Le chemin de la police dans le dossier contenant les polices d'écritures
    \param pTailleEcriture Un entier contenant la taille de la police.
    \return Une structure TTF_Font contenant la police chargée.
*/
TTF_Font * chargerPoliceEcriture(const char pChemin[], int pTailleEcriture);

#endif
