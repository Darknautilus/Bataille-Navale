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

#include "../model/Partie.h"

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
int sauvegardeGrille(Grille *grille, FILE *fichier);

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

/**
 * Créer une partie à partir des données contenu dans le fichier de sauvegarde désigné.
 * \param[in] nomSauv Le nom du fichier de sauvegarde (dans le dossier saves)
 * \return Une structure de type TPartie avec les données du fichier de sauvegarde.
**/
TPartie* restaurerPartie(const char nomSauv[]);

/**
 * Restaure les bateaux dans la structure de type TPartie à partir du flux fichier.
 * \param[out] partie La partie à modifier.
 * \param[in] fichier Le flux où lire les données
 * \return 1 = pas d'erreur, autre = codeErreur
*/
int restaurerBateaux(TPartie *partie, FILE* fichier);

/**
 * Restaure les grilles dans la structure TPartie passée en paramètre à partir du flux fichier.
 * \param[out] partie La partie à remplir
 * \param[in] fichier Le flux où lire les données
 * \return 1 = pas d'erreur, autre = codeErreur
*/
int restaurerGrilles(TPartie * partie, FILE* fichier);

/**
 * Restaure les coups dans la pile de la structure de type TPartie à partir du flux fichier.
 * \param[out] partie La partie à modifier.
 * \param[in] fichier Le flux où lire les données
 * \return 1 = pas d'erreur, autre = codeErreur
*/
int restaurerCoups(TPartie *partie, FILE* fichier);

/**
 * Restaure les paramètres dans la structure de type TPartie à partir du flux fichier.
 * \param[out] partie La partie à modifier.
 * \param[in] fichier Le flux où lire les données
 * \return 1 = pas d'erreur, autre = codeErreur
*/
int restaurerParam(TPartie *partie, FILE* fichier);

#endif
