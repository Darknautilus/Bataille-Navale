/**
 * \file FichierSauvRes.h
 * \author Benoît Sauvère
 * \date 19/06/2012
 * \brief Controleur du fichier de sauvegarde
 *
 * Contient les déclarations des fonctions utilisées pour la sauvegarde et la restauration d'une partie.
*/

#ifndef FICHIERSAUVRES_H
#define FICHIERSAUVRES_H

#include "../model/partie.h"

/**
 * Sauvegarde la partie passée en paramète dans le fichier désigné.
 * (Voir la documentation pour la structure du fichier de sauvegarde)
 * \param[in] partie La partie à sauvegarder
 * \param[in] nomSauv Le nom du fichier (sauvegardé dans le fichier de sauvegarde)
 * \return 1 = pas d'erreur, autre = codeErreur
**/
int sauvegardePartie(TPartie *partie, const char nomSauv[]);

/**
 * Sauvegarde les bateaux de la partie
 * (Voir la documentation pour la structure du fichier de sauvegarde)
 * \param[in] partie La partie contenant les bateaux à sauvegarder
 * \param[in] fichier Le flux où écrire les données
 * \return 1 = pas d'erreur, autre = codeErreur
**/
int sauvegardeBateaux(TPartie *partie, FILE *fichier);

/**
 * Sauvegarde les grilles de la partie
 * (Voir la documentation pour la structure du fichier de sauvegarde)
 * \param[in] grille Un pointeur sur la grille à sauvegarder.
 * \param[in] fichier Le flux où écrire les données
 * \return 1 = pas d'erreur, autre = codeErreur
**/
int sauvegardeGrilles(Grille *grille, FILE *fichier);

/**
 * Sauvegarde les coups de la pile de la partie
 * (Voir la documentation pour la structure du fichier de sauvegarde)
 * \param[in] partie La partie contenant les coups à sauvegarder
 * \param[in] fichier Le flux où écrire les données
 * \return 1 = pas d'erreur, autre = codeErreur
**/
int sauvegardeCoups(TPartie *partie, FILE *fichier);

/**
 * Sauvegarde les paramètres de la partie
 * (Voir la documentation pour la structure du fichier de sauvegarde)
 * \param[in] partie La partie contenant les paramètres à sauvegarder
 * \param[in] fichier Le flux où écrire les données
 * \return 1 = pas d'erreur, autre = codeErreur
**/
int sauvegardeParam(TPartie *partie, FILE *fichier);

#endif
