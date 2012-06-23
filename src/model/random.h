/**
 * \file Random.h
 * \author Aurélien Bertron
 * \date 10 juin 2012
 * \brief Module Aléatoire Headers
 *
 * Contient les déclarations du module d'aléatoire
*/
 
#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>

/**
 * Initialise le générateur de nombres aléatoires
 * À n'appeler qu'une seule fois en début de programme
*/
void initRandom(void);

/**
 * Génère un nombre aléatoirement dans un intervalle donné
 * \param[in] pNbMin Borne inférieure de l'intervalle
 * \param[in] pNbMax Borne supérieure de l'intervalle
 * \return Le nombre généré
*/
int nombreAleatoire(int pNbMin, int pNbMax);

/**
 * Choisit au hasard une ligne dans un fichier
 * Le fichier doit être ouvert en lecture
 * \param[out] pMot Le mot pioché
 * \param[in,out] pDesc Le descripteur du fichier ouvert en lecture
 * \param[in] longMax Longueur maximale d'une ligne du fichier
*/
void choixMotHasard(char * pMot, FILE * pDesc, int longMax);

#endif