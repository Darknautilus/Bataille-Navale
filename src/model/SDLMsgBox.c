#include "model/SDLMsgBox.h"

#include <stdlib.h>
#include <string.h>

SDL_MsgBox * creerMsgBox(int pAbs, int pOrd, int pLarg, int pHaut)
{
    SDL_MsgBox * nouvMsgBox = (SDL_MsgBox*)malloc(sizeof(SDL_MsgBox));

    nouvMsgBox->abscisse = pAbs;
    nouvMsgBox->ordonnee = pOrd;
    nouvMsgBox->largeur = pLarg;
    nouvMsgBox->hauteur = pHaut;

    return nouvMsgBox;
}

void setMsg(SDL_MsgBox * pMBox, char * pTexte)
{
    free(pMBox->texte);
    pMBox->texte = (char*)malloc(strlen(pTexte) * sizeof(char));

    strcpy(pMBox->texte, pTexte);
}

int nbLinMsg(char * pTexte)
{
    int i = 0, nbLignes = 1;

    while(pTexte[i] != '\0')
    {
        if(pTexte[i] == '\n')
            nbLignes++;
        i++;
    }
    return nbLignes;
}

int longLinMax(char * pTexte)
{
    int i = 0, longLin = 0, longMax = 0;

    while(pTexte[i] != '\0')
    {
        if(pTexte[i] == '\n')
        {
            if(longLin > longMax)
                longMax = longLin;
            longLin = 0;
        }
        else
            longLin++;
    }

    if(longLin > longMax)
        longMax = longLin;

    return longMax;
}

void libererMsgBox(SDL_MsgBox * pMBox)
{
    free(pMBox->texte);
    free(pMBox);
}
