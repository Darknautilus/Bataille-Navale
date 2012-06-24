/**
 *   \file FichierDebug.h
 *   \author Benoît Sauvère
 *   \date 03 juin 2012
 *   \brief Contrôleur Débogage
 *
 *   Contient les déclarations du module Debug.
 *   Ces fonction servent à écrire facilement des messages pour indiquer le déroulement de certaines opérations.
 *   Un fichier texte est généré au fur et à mesure.
*/

#ifndef DEBUG_H
#define DEBUG_H

/**
    Initialise les fonction de debogage.
    \return 0 si tout est OK. 1 si le fichier n'a pas pu Ítre crÈe.
*/
int init_debug();

/**
	Termine le debug et enregistre dans le fichier
	\return 0 si tout est OK. 1 en cas d'erreur.
*/
int detruire_debug();

/**
    InsËre dans le fichier de debug une entrÈe de type "SDL".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgSDL (const char message[]);

/**
    InsËre dans le fichier de debug une entrÈe de type "Information".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgInfo (const char message[]);

/**
    InsËre dans le fichier de debug une entrÈe de type "Attention".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgAttention (const char message[]);

/**
    InsËre dans le fichier de debug une entrÈe de type "Erreur".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgErreur (const char message[]);

/**
    InsËre dans le fichier de debug une entrÈe de type "Erreur fatale".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgFatal (const char message[]);

/**
    InsËre dans le fichier de debug une entrÈe avec le prefixe designÈ.
    \param prefixe Le prefixe du message.
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int debug (const char prefixe[], const char message[]);

#endif
