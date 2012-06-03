#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include "includeSDL.h"
#include "vueUtilsSDL.h"

#define SDL_BOUTON_KLONGMAX 30 /**< \brief Longueur maximum du texte du bouton */
#define SDL_BOUTON_KESP_VERT 5 /**< \brief Espacement vertical du texte avec le bord du bouton */
#define SDL_BOUTON_KESP_HORI 15 /**< \brief Espacement horizontal du texte avec le bord du bouton */

#define SDL_BOUTON_KCOULTXT_R 0 /**< \brief Couleur du texte RGB R */
#define SDL_BOUTON_KCOULTXT_G 0 /**< \brief Couleur du texte RGB G */
#define SDL_BOUTON_KCOULTXT_B 0 /**< \brief Couleur du texte RGB B */

// Couleur du bouton
#define SDL_BOUTON_KCOUL_R 200 /**< \brief Couleur du bouton normal RGB R */
#define SDL_BOUTON_KCOUL_G 207 /**< \brief Couleur du bouton normal RGB G */
#define SDL_BOUTON_KCOUL_B 212 /**< \brief Couleur du bouton normal RGB B */

typedef struct
{
	int abscisse;
	int ordonnee;
	char texte[SDL_BOUTON_KLONGMAX];
	int tailleTexte;
	int longTexte;
	int largCarac;
}SDL_Bouton;

SDL_Bouton * CreerBouton(char * pTexte, SDL_Rect * pCoord, int pTailleTexte);

void AfficherBouton(SDL_Bouton * pBouton);

int ClicSurBouton(SDL_Bouton * pBouton, SDL_Rect * positionClic);

void LibererBouton(SDL_Bouton * pBouton);

#endif