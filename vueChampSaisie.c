#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>

#include "champSaisie.h"
#include "vueChampSaisie.h"

#include "vueUtilsSDL.h"

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
    
    champBG = SDL_CreateRGBSurface(SDL_HWSURFACE, champ->longMax*13+20, champ->tailleTexte+10, 32, 0, 0, 0, 0);
    if(champ->onFocus == CHAMP_ACTIF)
        couleurFondChamp = SDL_MapRGB(champBG->format, 255, 255, 255);
    else
        couleurFondChamp = SDL_MapRGB(champBG->format, 200, 207, 212);
    SDL_FillRect(champBG, NULL, couleurFondChamp);
    
    texte = TTF_RenderText_Blended(police, champ->chaine, couleurTexte);
    
    SDL_BlitSurface(champBG, NULL, ecran, &positionChamp);
    SDL_BlitSurface(texte, NULL, ecran, &positionTexte);
    
    SDL_Flip(SDL_GetVideoSurface());
    
    SDL_FreeSurface(champBG);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}

void EditerChamp(ChampSaisie * champ)
{
    int continuer = 1;
    int etatEvent;
    
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    
    
    /*
     L'utilisation des caractères Unicode nous empêche d'utiliser AttendreEvent() qui ne les prend pas en charge
     La gestion d'Unicode s'active au début du sous-programme puis se désactive à la fin
     */
    
    SDL_EnableUNICODE(SDL_ENABLE);
    
    while (continuer)
    {
        etatEvent = AttendreEvent(positionClic, touche);
        
        if(etatEvent == 1)
        {
            if(!ClicSurChamp(champ, positionClic))
            {
                ChangeFocus(champ, CHAMP_INACTIF);
                continuer = 0;
            }
        }
        else if(etatEvent == 2)
        {
            if(touche->sym == SDLK_BACKSPACE)
                champ->chaine = SupprimerDernierChar(champ->chaine);
            else
                champ->chaine = AjouterCharFin(champ->chaine, (char)(touche->unicode));
            
        }
        AfficherChamp(champ, SDL_GetVideoSurface());
    }
    
    SDL_EnableUNICODE(SDL_DISABLE);
    
}