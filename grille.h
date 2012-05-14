/**
 * \file grille.h
 * \author Aurélien Bertron
 * \date 21 avril 2012
 * \brief Header modèle grille
 *
 * Contient les types et en-têtes des fonctions du module de grille
 *
 */

#ifndef GRILLE_H
#define GRILLE_H

#define KLARGCASE 40
#define KHAUTEURCASE 40

#define KTAILLEPOLICE 30
#define KESP_VERT 5
#define KESP_HORI 5

/**
 * \enum EtatCase
 * \brief Définit l'aspect de la case
*/
typedef enum {
    GRILLE_CASE_NORMAL, /**< Fond case normal */
    GRILLE_CASE_TOUCHE, /**< Ajout d'un signal "touché" */
    GRILLE_CASE_COULE /**< Ajout d'un signal "coulé" */
} EtatCase;

/**
 * \struct CaseGrille
 * \brief Contient les informations d'une case
*/
typedef struct
{
    EtatCase etatCase; /**< État de la case */
}
CaseGrille;

/**
 * \struct Ligne
 * \brief Tableau dynamique de cases
*/
typedef CaseGrille ** Ligne;

/**
 * \struct Grille
 * \brief Matrice
*/
typedef struct
{
	Ligne * TabLignes;/**< Tableau dynamique de lignes */
	int NbLin;/**< Nombre de lignes de la matrice */
	int NbCol;/**< Nombre de colonnes de la matrice */
	int abscisse;/**< Abscisse de la grille à l'écran */
	int ordonnee;/**< Ordonnée de la grille à l'écran */
}
Grille;

/**
 * \struct Coord
 * \brief Coordonnées dans la grille
 *
 * Cette structure représente les coordonnées dans la grille.
 * Il est important de différencier coordonnées dans la grille et coordonnées dans l'écran.
 * Dans le cas de la bataille navale, les numéros de ligne sont normalement des lettres mais il n'est pas nécessaire de les traiter comme tels, car tout est transparent pour l'utilisateur (saisie à la souris)
*/
typedef struct
{
	int noLin; /**< Numéro de ligne de la grille */
	int noCol; /**< Numéro de colonne de la grille */
} Coord;

/**
 * \brief Constructeur de grille
 *
 * \param[in] nbLin Nombre de lignes de la grille
 * \param[in] nbCol Nombre de colonnes de la grille
 *
 * \return Une grille initialisée ou NULL en cas d'erreur
 *
 * Ce constructeur initialise une grille de nbLin lignes et nbCol colonnes.
 * Attention, nbLin et nbCol doivent être strictement supérieurs à zéro.
*/
Grille * CreerGrille(int nbLin, int nbCol);

/**
 * \brief Récupère une case
 *
 * \param[in] grille
 * \param[in] coord Coordonnées dans la grille de la case
 *
 * \return La case aux coordonnées indiquées
 *
 * Récupère une case de la grille.
 * Attention, ligne et colonne doivent etre coherents avec les dimensions de la grilles
*/
CaseGrille * Consulter(Grille * grille, Coord coord);

/**
 * \brief Définit l'état d'une case
 *
 * \param[in] grille
 * \param[in] coord Coordonnées de l'élément à insérer dans la grille
 * \param[in] etat État de la case à modifier
 *
 * \return La grille modifiée
 *
 * Définit l'état d'une case dans la grille.
 * Attention la grille doit être initialisée
*/
Grille * SetEtatCase(Grille * grille, Coord coord, EtatCase etat);

/**
 * \brief Efface la grille
 *
 * \param[in] grille
 *
 * \return La grille modifiée
 *
 * Efface la grille en la remettant à l'état normal
 * Attention, la grille doit être initialisée
*/
Grille * EffacerGrille(Grille * grille);

/**
 * \brief Libère la grille en mémoire
 *
 * \param[in] grille
 *
 * Attention, la grille doit être initialisée
*/
void LibererGrille(Grille * grille);

#endif
