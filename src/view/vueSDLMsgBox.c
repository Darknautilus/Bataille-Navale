#include "VueSDLMsgBox.h"

#include "../model/SDLMsgBox.h"

#include "includeSDL.h"
#include "VueUtilsSDL.h"

void msgBox(int pAbs, int pOrd, char * pTexte, int pTailleTexte)
{
    int largeur, hauteur;
    int longMaxLin, nbLin;
    SDL_MsgBox * msgBox;
    SDL_Surface * fond, * boite;
    SDL_Rect positionElem;
    int controleEvent;
    SDL_Rect * coordClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    int continuer = 1;
    
    longMaxLin = longLinMax(pTexte);
    nbLin = nbLinMsg(pTexte);
    
    largeur = longMaxLin*13 + 2*KPADDING;
    hauteur = nbLin*pTailleTexte + 2*KPADDING;
    
    msgBox = creerMsgBox(pAbs, pOrd, largeur, hauteur);
    setMsg(msgBox, pTexte);
    
    fond = SDL_CreateRGBSurface(SDL_HWSURFACE, SDL_GetVideoSurface()->w, SDL_GetVideoSurface()->h, 32, 0, 0, 0, 0);
    SDL_FillRect(fond, NULL, SDL_MapRGBA(SDL_GetVideoSurface()->format, 0, 0, 0, 0.5));
    
    boite = SDL_CreateRGBSurface(SDL_HWSURFACE, largeur, hauteur, 32, 0, 0, 0, 0);
    SDL_FillRect(boite, NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0, 0, 0));
    
    positionElem.x = 0;
    positionElem.y = 0;
    SDL_BlitSurface(fond, NULL, SDL_GetVideoSurface(), &positionElem);
    positionElem.x = pAbs;
    positionElem.y = pOrd;
    SDL_BlitSurface(boite, NULL, SDL_GetVideoSurface(), &positionElem);
    positionElem.x = pAbs+KPADDING;
    positionElem.y = pOrd+KPADDING;
    EcrireTexte(pTexte, pTailleTexte, positionElem, "default.ttf");
    
    SDL_Flip(SDL_GetVideoSurface());
    
    while(continuer)
    {
        controleEvent = AttendreEvent(coordClic, touche);
        if(controleEvent == 2 && ToucheSpec(touche) == SDLK_RETURN)
            continuer = 0;
    }
    
    free(coordClic);
    free(touche);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(boite);
    libererMsgBox(msgBox);
}