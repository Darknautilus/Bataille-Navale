/**
 * \file VueBateau.h
 * \author Aurélien Bertron
 * \date 19 juin 2012
 * \brief Vue affichage des bateaux.
 *
 *  Contient les déclarations des fonctions utilisées pour la sauvegarde et la restauration d'une partie.
*/

#ifndef VUEBATEAU_H_INCLUDED
#define VUEBATEAU_H_INCLUDED

#include "../model/Grille.h"
#include "../model/Bateau.h"

// insère un bateau dans une grille, renvoie NULL si ce n'est pas possible.
// On peut également insérer des bateaux touché ou coulé (pour le chargement d'une partie par ex.)
Grille * insertBateau(Grille * grille, TBateau * bat);


#endif // VUEBATEAU_H_INCLUDED
