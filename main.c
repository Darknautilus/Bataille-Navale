#include <stdio.h>
#include <stdlib.h>

// Permet la portabilité du programme
#ifdef __APPLE__

#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#else

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#endif

#include "utilsSDL.h"
#include "vueUtilsSDL.h"

#include "menu.h"

#include "parametre.h"

#include "grille.h"
#include "vueGrille.h"

#include "champSaisie.h"
#include "vueChampSaisie.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;
    
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                exit(EXIT_FAILURE);
                break;
            case SDL_KEYDOWN:
                continuer = 0;
                break;
        }
    }
    
}

void controleurParametreVersionTest(Tparam *param)
{
    newTParam(1 , param);

    // boucles avec void newTParam(int pIdBateau , Tparam * pP, char pNom[], int pCouleur , EType pType) doit remplacer ce qui suit
    setIemeInfoBateauTParam(0 , param, "redon", 0 , remorqueur);
    setIemeInfoBateauTParam(1 , param, "peninou", 1 , porteAvion);
    setIemeInfoBateauTParam(2 , param, "canut", 2 , sousMarin);
    setIemeInfoBateauTParam(3, param , "caplain", 3 , cargot);
    setIemeInfoBateauTParam(4 , param , "bruel", 4 , remorqueur);
    setIemeInfoBateauTParam(5 , param , "inglebert", 5 , porteAvion);
    setIemeInfoBateauTParam(6 , param , "verdier", 0 , sousMarin);
    setIemeInfoBateauTParam(7 , param , "nonne", 1 , cargot);


}


int main(int argc, char ** argv)
{
    SDL_Surface * ecran;
    
    int choixMenu;
    int continuer = 1;
    
    ecran = DemarrerSDL(800, 600, "Bataille Navale");
        
    AfficherMenuAccueil();
    
    while (continuer)
    {
        choixMenu = AfficherMenuRacine();
    
        switch (choixMenu) 
        {
            case 1:// Nouvelle Partie
                MenuNouvellePartie();
                break;
            
            case 5:// Quitter
                continuer = 0;
                break;
        }    
    }
            
    ArreterSDL();
    
    return 0;
}
