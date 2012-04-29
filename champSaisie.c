#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "champSaisie.h"
#include "utilsSDL.h"

ChampSaisie * CreerChamp(int longMax, int taille, int abscisse, int ordonnee)
{
    ChampSaisie * champ;
    
    champ = (ChampSaisie*)malloc(sizeof(ChampSaisie));
    
    champ->chaine = (char*)malloc((longMax+1)*sizeof(char));
    champ->longMax = longMax;
    champ->tailleTexte = taille;
    champ->abscisse = abscisse;
    champ->ordonnee = ordonnee;
    champ->onFocus = 0;
    
    return champ;
}

ChampSaisie * InitTexte(ChampSaisie * champ, char * texte)
{
    strcpy(champ->chaine, texte);
    
    return champ;
}

void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran)
{
    SDL_Surface * champBG, * texte;
    TTF_Font * police;
    SDL_Color couleurTexte = {0,0,0};
    SDL_Rect positionChamp, positionTexte;
    
    police = TTF_OpenFont("Fonts/apple.ttf", champ->tailleTexte);
    
    positionChamp.x = champ->abscisse;
    positionChamp.y = champ->ordonnee;
    positionTexte.x = champ->abscisse+5;
    positionTexte.y = champ->ordonnee+5;
    
    champBG = SDL_CreateRGBSurface(SDL_HWSURFACE, champ->longMax*5+10, champ->tailleTexte+10, 32, 0, 0, 0, 0);
    SDL_FillRect(champBG, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    
    texte = TTF_RenderText_Solid(police, champ->chaine, couleurTexte);
    
    SDL_BlitSurface(champBG, NULL, ecran, &positionChamp);
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    
    SDL_Flip(SDL_GetVideoSurface());
    
    SDL_FreeSurface(champBG);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}

int ClicSurChamp(ChampSaisie * champ, SDL_Rect positionClic)
{    
    if(positionClic.x >= champ->abscisse && positionClic.x <= champ->longMax*5+10 &&
        positionClic.y >= champ->ordonnee && positionClic.y <= champ->tailleTexte+1)
    {
        return 1;
    }
    else
        return 0;
}

ChampSaisie * ChangeFocus(ChampSaisie * champ)
{
    if(champ->onFocus)
        champ->onFocus = 0;
    else
        champ->onFocus = 1;
    
    return champ;
}

void LibererChamp(ChampSaisie * champ)
{
    free(champ->chaine);
    free(champ);
}