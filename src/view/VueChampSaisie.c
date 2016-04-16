#include "view/VueChampSaisie.h"

#include "view/IncludeSDL.h"
#include "view/VueUtilsSDL.h"

#include "model/ChampSaisie.h"

#include "ctrl/UtilsPoliceEcriture.h"
#include "ctrl/FichierDebug.h"
#include "ctrl/UtilsSDL.h"

#include <string.h>

void afficherChamp(ChampSaisie * champ)
{
    SDL_Surface * champBG, * texte;
    TTF_Font * police;
    SDL_Color couleurTexte = {KCOULTXT_R, KCOULTXT_G, KCOULTXT_B};
    SDL_Rect positionChamp, positionTexte;
    Uint32 couleurFondChamp;

    police = chargerPoliceEcriture("default.ttf", champ->tailleTexte);

    positionChamp.x = champ->abscisse;
    positionChamp.y = champ->ordonnee;
    positionTexte.x = champ->abscisse+KESP_HORI;
    positionTexte.y = champ->ordonnee+KESP_VERT;

    champBG = GetNewRGBASurface(champ->longMax*champ->largCarac+2*KESP_HORI,
        champ->tailleTexte+2*KESP_VERT);

    if(champ->onFocus == CHAMP_ACTIF)
        couleurFondChamp = SDL_MapRGB(champBG->format, KCOULEDIT_R, KCOULEDIT_G, KCOULEDIT_B);
    else
        couleurFondChamp = SDL_MapRGB(champBG->format, KCOULNORM_R, KCOULNORM_G, KCOULNORM_B);

    SDL_FillRect(champBG, NULL, couleurFondChamp);

    texte = TTF_RenderText_Blended(police, champ->chaine, couleurTexte);

    SDL_BlitSurface(champBG, NULL, GetMainScreen(), &positionChamp);
    SDL_BlitSurface(texte, NULL, GetMainScreen(), &positionTexte);

    SDL_FreeSurface(champBG);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);
}

void editerChamp(ChampSaisie * champ)
{
    int continuer = 1;
    int etatEvent;

    SDL_Event event;
    SDL_Rect * positionClic = malloc(sizeof(SDL_Rect));

    changeFocus(champ, CHAMP_ACTIF);

    SDL_StartTextInput();

    afficherChamp(champ);
    UpdateWindow(SDL_FALSE);
    
    while (continuer)
    {
        int render = 0;
        
        if (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    exit(EXIT_FAILURE);
                    break;
                
                case SDL_KEYDOWN: {
                    if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE && strlen(champ->chaine) > 0) {
                        supprimerDernierChar(champ->chaine);
                        render = 1;
                    }
                    break;
                }
                case SDL_TEXTINPUT: {
                    int insertLen = strlen(event.text.text);
                    if (strlen(champ->chaine) + insertLen < champ->longMax) {
                        strcat(champ->chaine, event.text.text);
                        render = 1;
                    }
                    break;
                }
                case SDL_MOUSEBUTTONDOWN: {
                    positionClic->x = event.button.x;
                    positionClic->y = event.button.y;
                    if(!clicSurChamp(champ, positionClic))
                    {
                        changeFocus(champ, CHAMP_INACTIF);
                        continuer = 0;
                        render = 1;
                    }
                    break;
                }
            }
        }
        
        if (render) {
            afficherChamp(champ);
            UpdateWindow(SDL_FALSE);
        }

    }
    SDL_StopTextInput();

    free(positionClic);
}

int clicSurChamp(ChampSaisie * champ, SDL_Rect * positionClic)
{
	int codeRetour = 0;

	if(positionClic->x >= champ->abscisse && positionClic->x <= champ->abscisse+champ->longMax*champ->largCarac+2*KESP_HORI &&
	positionClic->y >= champ->ordonnee && positionClic->y <= champ->ordonnee+champ->tailleTexte+2*KESP_VERT)
	{
		codeRetour = 1;
	}

	return codeRetour;

}
