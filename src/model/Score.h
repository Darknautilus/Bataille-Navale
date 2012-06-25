/**
 *   \file Score.h
 *   \author Benoît Sauvère
 *   \date 14 juin 2012
 *   \brief Modèle Score
 *
 *   Contient les déclarations de gestion des structures Score.
*/

#ifndef SCORE_H
#define SCORE_H

#include "../model/joueur.h"

/**
 * \struct Score
 * \brief Contient un score avec le nom du joueur.
*/
typedef struct{
    char nom[KLGNOMJ];  /**< Le nom du joueur qui à réalisé le score */
    int score;          /**< Le score du joueur **/
}
Score;

/**
    Contructeur du module Score.
    \return Un pointeur sur un score correctement alloué.
**/
Score* creerScore();

/**
    Contructeur du module Score avec paramétrage.
    \param[in] score Valeur du score
    \param[in] nom Nom du joueur
    \return Un pointeur sur un score correctement alloué et initialisé.
**/
Score* creerScoreP(int score, const char nom[]);

/**
    Retourne le score d'un joueur.
    \param[in] score Un pointeur sur le score dont on veux la valeur.
*/
int getScore(Score *score);

/**
    Retourne le nom du joueur qui à réalisé le score.
    \param[in] score Un pointeur sur le score dont on veux le nom du joueur.
*/
char* getNomScore(Score *score);

/**
    Modifie le score d'une structure score.
    \param[out] score Un pointeur sur le score dont on veut modifier le score.
    \param[in] nouvScore La nouvelle valeur du score.
*/
void setScore(Score *score, int nouvScore);

/**
    Modifie le score d'une structure score.
    \param[out] score Un pointeur sur le score dont on veut modifier le score.
    \param[in] nouvNom Une chaine de caractères contenant le nouveau nom.
*/
void setNomScore(Score *score, const char nouvNom[] );

/**
    Libère les ressources liées à un score.
    \param[in] score Un pointeur sur le score à libérer.
**/
void libererScore(Score *score);

#endif
