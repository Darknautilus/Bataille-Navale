/**
 *   \file fichierDebug.h
 *   \author Benoit Sauvere
 *   \date 03 juin 2012
 *   \brief Module Debug
 *
 *   Contient les d�claration du module Debug.
 *   Ces fonction servent � �crire facilement des messages pour indiquer le d�roulement de certaines op�rations.
*/
#ifndef DEBUG_H
#define DEBUG_H

/**
    Initialise les fonction de debogage.
    \return 0 si tout est OK. 1 si le fichier n'a pas pu �tre cr�e.
*/
int init_debug();

/**
	Termine le debug et enregistre dans le fichier
	\return 0 si tout est OK. 1 en cas d'erreur.
*/
int detruire_debug();

/**
    Ins�re dans le fichier de debug une entr�e de type "SDL".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgSDL (const char message[]);

/**
    Ins�re dans le fichier de debug une entr�e de type "Information".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgInfo (const char message[]);

/**
    Ins�re dans le fichier de debug une entr�e de type "Attention".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgAttention (const char message[]);

/**
    Ins�re dans le fichier de debug une entr�e de type "Erreur".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgErreur (const char message[]);

/**
    Ins�re dans le fichier de debug une entr�e de type "Erreur fatale".
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int dgFatal (const char message[]);

/**
    Ins�re dans le fichier de debug une entr�e avec le prefixe design�.
    \param prefixe Le prefixe du message.
    \param message Le message a inserer.
    \return 0 si tout est OK. 1 sinon.
*/
int debug (const char prefixe[], const char message[]);

#endif
