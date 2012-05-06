#ifndef VUE_CHAMP_SAISIE_H
#define VUE_CHAMP_SAISIE_H

#include "champSaisie.h"

/*
 Affiche le champ aux coordonnees données lors de la création.
 Le deuxième paramètre, l'écran peut être donné avec SDL_GetVideoSurface()
 */
void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran);

/*
 Passe le champ en mode édition (possibilité d'ajouter des caractères et d'en supprimer)
 Pour sortir du mode édition, il est necessaire de cliquer hors du champ
 */
void EditerChamp(ChampSaisie * champ);

/*
 Renvoit 1 si le clic est sur le champ et 0 sinon
 
 positionClic : coordonnées du clic
 */
int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic);

#endif