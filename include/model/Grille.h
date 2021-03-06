/**
 * \file Grille.h
 * \author Aurelien Bertron, Benoît Sauvère
 * \date 21 avril 2012
 * \brief Modèle Grille
 *
 * Contient les types et en-tetes des fonctions du module de grille
 *
 */

#ifndef GRILLE_H
#define GRILLE_H

#define KLARGGRILLE 10   /**< \brief Largeur de la grille */
#define KHAUTGRILLE 10   /**< \brief Hauteur de la grille */

#define KLARGCASE 30     /**< \brief Largeur d'une case */
#define KHAUTEURCASE 30  /**< \brief Hauteur d'une case */

#define KTAILLEPOLICE 30 /**< \brief Taille de police */
#define KESP_CASE_VERT 5 /**< \brief Espace vertical entre les cases */
#define KESP_CASE_HORI 5 /**< \brief Espace horizontal entre les cases */
#define KIDCOULDEFAUT 0  /**< \brief Indice de la couleur par défaut de la grille */

/**
 * \enum EtatCase
 * \brief Definit l'aspect de la case
*/
typedef enum {
    GRILLE_CASE_NORMAL, /**< Fond case normal */
    GRILLE_CASE_TOUCHE, /**< Ajout d'un signal "touche" */
    GRILLE_CASE_COULE,  /**< Ajout d'un signal "coule" */
    GRILLE_CASE_EAU     /**< Ajout d'un signal "a l'eau" */
} EtatCase;

/**
 * \struct CaseGrille
 * \brief Contient les informations d'une case
*/
typedef struct
{
    EtatCase etatCase;      /**< État de la case */
	int couleur;            /**< Numéro de la couleur dans la table des couleurs */
	int idBateauOccupe;     /**< Id du bateau qui occupe la case. */
}
CaseGrille;

/**
 * \struct Ligne
 * \brief Tableau dynamique de cases
*/
typedef CaseGrille * Ligne;

/**
 * \struct Grille
 * \brief Matrice
*/
typedef struct
{
	Ligne * Matrice;  /**< Tableau dynamique de lignes */
	int NbLin;        /**< Nombre de lignes de la matrice */
	int NbCol;        /**< Nombre de colonnes de la matrice */
	int abscisse;     /**< Abscisse de la grille à l'écran */
	int ordonnee;     /**< Ordonnée de la grille à l'écran */
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
Grille * creerGrille(int nbLin, int nbCol);

/**
 * \return Le nombre de lignes de la grille
 * \param[in] pGrille
*/
int getNbLin(Grille * pGrille);

/**
 * \return Le nombre de colonnes de la grille
 * \param[in] pGrille
 */
int getNbCol(Grille * pGrille);

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
CaseGrille * consulter(Grille * grille, Coord coord);

/**
 * \brief Récupère l'id d'un bateau
 *
 * \param[in] grille
 * \param[in] coord Coordonnées dans la grille de la case ou est le bateau
 *
 * \return L'id du bateau qui occupe la case. -1 si pas de bateaux.
 *
 * Récupère l'id du bateau occupant une case.
*/
int getIdBateauSurCase(Grille *grille, Coord coord);


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
Grille * setEtatCase(Grille * grille, Coord coord, EtatCase etat);

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
Grille * effacerGrille(Grille * grille);

/**
 * \brief Libère la grille en mémoire
 *
 * \param[in] grille
 *
 * Attention, la grille doit être initialisée
*/
void libererGrille(Grille * grille);

#endif
