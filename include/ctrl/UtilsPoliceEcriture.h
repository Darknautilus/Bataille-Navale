/**
 *   \file UtilsPoliceEcriture.h
 *   \author Benoit Sauvère
 *   \date 03 juin 2012
 *   \brief Contrôleur Utillitaire Police Ecriture
 *
 *   Contient les déclarations pour le module des utilitaires de chargement des polices d'écriture.
*/

#ifndef UTILSFONT_H
#define UTILSFONT_H

#include "view/IncludeSDL.h"

/**
    Charge une police d'Ècriture contenue dans le fichier des polices d'Ècriture
    \param pChemin Le chemin de la police dans le dossier contenant les polices d'Ècritures
    \param pTailleEcriture Un entier contenant la taille de la police.
    \return Une structure TTF_Font contenant la police chargÈe.
*/
TTF_Font * chargerPoliceEcriture(const char pChemin[], int pTailleEcriture);

#endif
