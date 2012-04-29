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

int ChainePleine(ChampSaisie * champ)
{
    if(strlen(champ->chaine) < champ->longMax-1)
        return 0;
    else
        return 1;
}

void AfficherChamp(ChampSaisie * champ, SDL_Surface * ecran)
{
    SDL_Surface * champBG, * texte;
    TTF_Font * police;
    SDL_Color couleurTexte = {0,0,0};
    SDL_Rect positionChamp, positionTexte;
    Uint32 couleurFondChamp;
    
    police = TTF_OpenFont("Fonts/apple.ttf", champ->tailleTexte);
    
    positionChamp.x = champ->abscisse;
    positionChamp.y = champ->ordonnee;
    positionTexte.x = champ->abscisse+5;
    positionTexte.y = champ->ordonnee+5;
    
    champBG = SDL_CreateRGBSurface(SDL_HWSURFACE, champ->longMax*5+10, champ->tailleTexte+10, 32, 0, 0, 0, 0);
    if(champ->onFocus)
        couleurFondChamp = SDL_MapRGB(champBG->format, 255, 255, 255);
    else
        couleurFondChamp = SDL_MapRGB(champBG->format, 200, 207, 212);
    SDL_FillRect(champBG, NULL, couleurFondChamp);
    
    texte = TTF_RenderText_Solid(police, champ->chaine, couleurTexte);
    
    SDL_BlitSurface(champBG, NULL, ecran, &positionChamp);
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    
    SDL_Flip(SDL_GetVideoSurface());
    
    SDL_FreeSurface(champBG);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}

int ClicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic)
{    
    if(positionClic->x >= champ->abscisse && positionClic->x <= champ->abscisse+champ->longMax*5+10 &&
        positionClic->y >= champ->ordonnee && positionClic->y <= champ->ordonnee+champ->tailleTexte+10)
    {
        return 1;
    }
    else
        return 0;
}

ChampSaisie * ChangeFocus(ChampSaisie * champ, int val)
{
    champ->onFocus = val;
    return champ;
}

int EstNombre(SDL_Event * event)
{
    if(event->key.keysym.sym >= SDLK_0 && event->key.keysym.sym <= SDLK_9)
        return 1;
    else
        return 0;
}

int EstLettre(SDL_Event * event)
{
    if(event->key.keysym.sym >= SDLK_a && event->key.keysym.sym <= SDLK_z)
        return 1;
    else
        return 0;
}

char * SupprimerDernierChar(char * chaine)
{
    int i=0;
    while(chaine[i]!='\0')
        i++;
    
    chaine[i-1] = '\0';
    
    return chaine;
}

char * AjouterCharFin(char * chaine, char charEnt)
{
    int i=0;
    while (chaine[i]!='\0')
        i++;
    
    chaine[i+1] = '\0';    
    chaine[i] = charEnt;

    return chaine;
}

void EditerChamp(ChampSaisie * champ)
{
    SDL_Event event;
    SDL_Rect positionClic;
    int continuer = 1;
    
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                exit(EXIT_FAILURE);
            break;
                
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    positionClic.x = event.button.x;
                    positionClic.y = event.button.y;
                    if(!ClicSurChamp(champ, &positionClic))
                    {
                        champ = ChangeFocus(champ, 0);
                        continuer = 0;
                    }
                }
            break;
            
            case SDL_KEYDOWN:
                if(!ChainePleine(champ))
                {
                    if(EstNombre(&event))
                    {
                        champ->chaine = AjouterCharFin(champ->chaine, '0' + event.key.keysym.sym - SDLK_0);
                    }
                    else if(EstLettre(&event))
                    {
                        champ->chaine = AjouterCharFin(champ->chaine, 'a' + event.key.keysym.sym - SDLK_a);
                    }
                }
                
                if(event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    champ->chaine = SupprimerDernierChar(champ->chaine);
                }
            break;
                
        }
        AfficherChamp(champ, SDL_GetVideoSurface());
    }
}

void LibererChamp(ChampSaisie * champ)
{
    free(champ->chaine);
    free(champ);
}