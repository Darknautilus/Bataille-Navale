/**
 * \file SDLMsgBox.h
 * \author Aurélien Bertron
 * \date 19 juin 2012
 * \brief Modèle de boîtes de messages.
 *
 * Contient les déclarations de gestion du modèle de boites de messages.
*/

#ifndef SDL_MESSAGE_BOX_H
#define SDL_MESSAGE_BOX_H

//#define KLONGMAXMSG 50
#define KPADDING 10

typedef struct
{
    int abscisse;
    int ordonnee;
    int largeur;
    int hauteur;
    char * texte;
}
SDL_MsgBox;

SDL_MsgBox * creerMsgBox(int pAbs, int pOrd, int pLarg, int pHaut);

void setMsg(SDL_MsgBox * pMBox, char * pTexte);

int nbLinMsg(char * pTexte);

int longLinMax(char * pTexte);

void libererMsgBox(SDL_MsgBox * pMBox);

#endif
