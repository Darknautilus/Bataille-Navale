#ifndef VUE_CHAMP_SAISIE_H
#define VUE_CHAMP_SAISIE_H


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

#endif