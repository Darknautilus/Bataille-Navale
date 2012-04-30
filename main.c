#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#include <SDL_ttf/SDL_ttf.h>

#include "utilsSDL.h"
#include "menu.h"

#include "parametre.h"
#include "grille.h"
#include "vueGrille.h"

#include "champSaisie.h"

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


int main()
{
    SDL_Surface * ecran;
    
    int choixMenu;
    int continuer = 1;
    
    ecran = DemarrerSDL(800, 600, "Bataille Navale");
        
    AfficherMenuAccueil();
    
    while (continuer)
    {
        choixMenu = AfficherMenuRacine();
        EffacerEcran();
    
        switch (choixMenu) 
        {
            case 1:// Nouvelle Partie
                MenuNouvellePartie();
                break;
            
            case 5:// Quitter
                exit(EXIT_SUCCESS);
                break;
        }
    
        SDL_Flip(ecran);
    }
    
    pause();
        
    ArreterSDL();
    
    return 0;
}
