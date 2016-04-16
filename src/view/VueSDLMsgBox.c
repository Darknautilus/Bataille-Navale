#include "view/VueSDLMsgBox.h"

#include "view/IncludeSDL.h"
#include "view/VueUtilsSDL.h"

#include "model/SDLMsgBox.h"
#include "ctrl/UtilsSDL.h"

void msgBox(int pAbs, int pOrd, char * pTexte, int pTailleTexte)
{
    int largeur, hauteur;
    int longMaxLin, nbLin;
    SDL_MsgBox * msgBox;
    SDL_Surface * fond, * boite;
    SDL_Rect positionElem;
    int controleEvent;
    SDL_Rect * coordClic = malloc(sizeof(SDL_Rect));
    SDL_Keysym touche;
    int continuer = 1;

    longMaxLin = longLinMax(pTexte);
    nbLin = nbLinMsg(pTexte);

    largeur = longMaxLin*13 + 2*KPADDING;
    hauteur = nbLin*pTailleTexte + 2*KPADDING;

    msgBox = creerMsgBox(pAbs, pOrd, largeur, hauteur);
    setMsg(msgBox, pTexte);

    fond = GetNewRGBASurface(GetMainScreen()->w, GetMainScreen()->h);
    SDL_FillRect(fond, NULL, SDL_MapRGBA(GetMainScreen()->format, 0, 0, 0, 0.5));

    boite = GetNewRGBASurface(largeur, hauteur);
    SDL_FillRect(boite, NULL, SDL_MapRGB(GetMainScreen()->format, 0, 0, 0));

    positionElem.x = 0;
    positionElem.y = 0;
    SDL_BlitSurface(fond, NULL, GetMainScreen(), &positionElem);
    positionElem.x = pAbs;
    positionElem.y = pOrd;
    SDL_BlitSurface(boite, NULL, GetMainScreen(), &positionElem);
    positionElem.x = pAbs+KPADDING;
    positionElem.y = pOrd+KPADDING;
    ecrireTexte(pTexte, pTailleTexte, positionElem, "default.ttf");

    UpdateWindow(SDL_TRUE);

    while(continuer)
    {
        controleEvent = attendreEvent(coordClic, &touche);
        if(controleEvent == 2 && touche.scancode == SDL_SCANCODE_RETURN)
            continuer = 0;
    }

    free(coordClic);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(boite);
    libererMsgBox(msgBox);
}
