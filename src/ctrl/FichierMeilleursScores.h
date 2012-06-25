/**
 *   \file FichierMeilleursScores.h
 *   \author Benoît Sauvère
 *   \date 19 juin 2012
 *   \brief Controlleur Meilleurs Scores
 *
 *   Contient les déclarations des fonction de gestions des meilleurs scores.
*/

#ifndef FICHIERMEILLEURSSCORES_H
#define FICHIERMEILLEURSSCORES_H

#include "../model/Joueur.h"
#include "../model/Score.h"

#include <stdio.h>

#define FIC_MEILLEURSSCORES "ressources/bestScores.dat"

#define MAX_MEILLEURS_SCORES 10

/**
    Détermine l'index d'un score dans un tableau de scores;
    \param[in] tabScore Un tableau de pointeurs de Score de MAX_MEILLEURS_SCORES cases.
    \param[in] score Un pointeur sur le score dont on veux déterminer l'index dans le tableau des scores.
    \return L'index du score dans tabScore. Retourne -1 si le score n'a pas sa place dans le tableau.
**/
int placeScoreTableau(Score* tabScores[], Score *score);

/**
    Ajoute un score dans le fichier de meilleurs scores.
    \param[in] score Un pointeur sur le score que l'on veut ajouter.
**/
void ajouterScore(Score *score);

/**
    Récupère un tableau de scores de MAX_MEILLEURS_SCORES structures Score.
    \return Un tableau de pointeurs de scores de MAX_MEILLEURS_SCORES cases. Si il n'y a pas assez de cases, les cases vides seront initialisée à -1 et "".
**/
Score** getMeilleursScoresFichier();

/**
    Ouvre le fichier contenant les meilleurs score en mode binaire.
    \param[in] modeOuverture Le mode d'ouverture dans lequel on veux ouvrir le fichier des meilleurs scores
    \return Un fichier pointant sur le fichiers meilleurs scores ouvert en mode lecture/écriture/binaire.
**/
FILE* ouvrirFichierMeilleursScores(const char modeOuverture[]);

/**
    Enregistre le tableau des scores dans le fichier des meilleurs scores.
    \param[in] tabScores Le tableau de pointeur de Score à écrire
**/
void enregistrerTabScore(Score* tabScores[]);

#endif
