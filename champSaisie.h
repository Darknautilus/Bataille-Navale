/**
 * \file champSaisie.h
 * \author Aurélien Bertron
 * \date 29 avril 2012
 * \brief Modele champ saisie
 *
 * Contient les types et en-têtes des fonctions du module de champs de saisie.
 * Ce module implémente la gestion du champ de saisie. Il permet à l'utilisateur de saisir une chaine de caractères.
*/

#ifndef CHAMP_SAISIE_H
#define CHAMP_SAISIE_H


#define KESP_VERT 5 /**< \brief Espacement vertical du texte avec le bord du champ */
#define KESP_HORI 5 /**< \brief Espacement horizontal du texte avec le bord du champ */

#define KCOULTXT_R 0 /**< \brief Couleur du texte RGB R */
#define KCOULTXT_G 0 /**< \brief Couleur du texte RGB G */
#define KCOULTXT_B 0 /**< \brief Couleur du texte RGB B */

// Couleur du champ (mode normal)
#define KCOULNORM_R 200 /**< \brief Couleur du champ normal RGB R */
#define KCOULNORM_G 207 /**< \brief Couleur du champ normal RGB G */
#define KCOULNORM_B 212 /**< \brief Couleur du champ normal RGB B */

// Couleur du champ (mode édition)
#define KCOULEDIT_R 255 /**< \brief Couleur du champ édition RGB R */
#define KCOULEDIT_G 255 /**< \brief Couleur du champ édition RGB G */
#define KCOULEDIT_B 255 /**< \brief Couleur du champ édition RGB B */

/**
 * \enum EtatChamp
 * \brief Etat d'un champ
 *
 * Constantes définissant l'activation ou non du champ.
*/
typedef enum{
    CHAMP_ACTIF, /**< Champ en mode édition */
    CHAMP_INACTIF /**< Champ en mode hors-édition */
} EtatChamp;

/**
 * \struct ChampSaisie
 * \brief Champ de saisie
*/
typedef struct
{
	char * chaine; /**< Chaine tapée dans le champ */
    int longMax; /**< Longueur maximum de la chaine */
    int tailleTexte; /**< Taille de la police de texte */
    int abscisse; /**< Abscisse du champ dans l'écran */
    int ordonnee; /**< Ordonnee du champ dans l'écran */ 
    EtatChamp onFocus; /**< Vaut CHAMP_ACTIF si le champ est actif (mode édition) et CHAMP_INACTIF sinon */
}ChampSaisie;

/**
 * \brief Initialise le champ
 *
 * \param[in] longMax Longueur maximale du champ
 * \param[in] taille Taille de la police
 * \param[in] abscisse Abscisse du champ dans l'écran
 * \param[in] ordonnee Ordonnée du champ dans l'écran
 *
 * \return Un champ de saisie initialisé et NULL en cas d'erreur
 *
 * Par défaut, le champ est inactif et vide.
*/
ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee);

/**
 * \brief Initialise le contenu du champ
 *
 * \param[in,out] champ
 * \param[in] chaine Chaine à insérer dans le champ
 *
 * Initialise le contenu du champ avec une chaine de caractères.
*/
void InitTexte(ChampSaisie * champ, const char * chaine);

/**
 * \brief Définit si le champ est plein
 *
 * \param[in] champ
 *
 * \return 1 si le champ est plein et 0 sinon
 *
 * Cette fonction teste si la chaine du champ n'est pas de la longueur maximale spécifiée à la création du champ.
*/
int ChainePleine(const ChampSaisie * champ);

/**
 * \brief Change l'état du champ
 *
 * \param[in,out] champ
 * \param[in] etat Nouvel état du champ
 *
 * Met le champ à l'état spécifié (activé ou non)
*/
void ChangeFocus(ChampSaisie * champ, EtatChamp etat);

/**
 * \brief Supprime le dernier caractère d'une chaine
 *
 * \param[in,out] chaine
 *
 * \return La chaine modifiée
*/
char * SupprimerDernierChar(char * chaine);

/**
 * \brief Ajoute un caractère à la fin de la chaine
 *
 * \param[in,out] chaine
 * \param[in] charEnt Caractère à insérer
 *
 * \return La chaine modifiée
 *
 * La chaine ne doit pas être pleine.
*/
char * AjouterCharFin(char * chaine, char charEnt);

/**
 * \brief Libère le champ en mémoire
 *
 * \param[in] champ Champ à libérer
 *
 * À ne pas oublier à la fin du programme
*/
void LibererChamp(ChampSaisie * champ);

#endif