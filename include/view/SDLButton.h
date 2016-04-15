/**
 * \file SDLButton.h
 * \author Aurélien Bertron
 * \date 28 mai 2012
 * \brief Vue des bouton SDL
 *
 * Contient les déclarations du module Bouton SDL
*/

#ifndef SDL_BUTTON_H
#define SDL_BUTTON_H

#include "view/IncludeSDL.h"
#include "view/VueUtilsSDL.h"

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

/**
 * \struct SDL_Bouton
 * \brief Outil de dessin de boutons
*/
typedef struct
{
	int abscisse; /**< Abscisse du bouton */
	int ordonnee; /**< Ordonnée du bouton */
	char texte[SDL_BOUTON_KLONGMAX]; /**< Texte du bouton */
	int tailleTexte; /**< Taille du texte */
	int longTexte; /**< Longueur du texte */
	int largCarac; /**< Largeur d'un caractère */
}SDL_Bouton;

/**
 * Crée un bouton.
 * \param pTexte Le texte du bouton.
 * \param pCoord Un pointeur sur les coordonnÈes
 * \param pTailleTexte Un entier contenant la taille du texte.
 * \return Une strucutre SDL_Bouton correctement initialisÈe.
*/
SDL_Bouton * creerBouton(char * pTexte, SDL_Rect * pCoord, int pTailleTexte);

/**
 * Affiche un bouton
 * \param[in] pBouton Un bouton
*/
void afficherBouton(SDL_Bouton * pBouton);

/**
 * Détermine si un clic est sur le bouton ou non
 * \param[in] pBouton Un bouton
 * \param[in] positionClic La position du clic
 * \return 1 si le clic est sur le bouton et 0 sinon
*/
int clicSurBouton(SDL_Bouton * pBouton, SDL_Rect * positionClic);

/**
 * Libère le bouton en mémoire
 * \param[in] pBouton Un bouton
*/
void libererBouton(SDL_Bouton * pBouton);

#endif
