#include "CtrlGrille.h"

#include "../model/champSaisie.h"

// Permet la portabilité du programme
#include "../view/includeSDL.h"
#include "../view/vueChampSaisie.h"
#include "../view/vueUtilsSDL.h"
#include "../view/vueGrille.h"
#include "../view/vueBateau.h"
#include "../view/SDLButton.h"
#include "../view/SDLImage.h"

#include "../ctrl/utilsSDL.h"
#include "../ctrl/fichierDebug.h"

#include "../test/test.h"
#include "../test/view/testVue.h"

#include "../model/bateau.h"

void EcranGrille(ChampSaisie * champ)
{
    Grille * grilleJoueur;
    SDL_keysym * touche = (SDL_keysym*)malloc(sizeof(SDL_keysym));
    SDL_Rect * positionClic = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	SDL_Rect positionTexte;
    int controleEvent;
    Coord coord;
    CaseGrille * caseGrille;

    int continuer = 1;


    grilleJoueur = CreerGrille(10, 10);


    EffacerEcran();
    afficherGrille(grilleJoueur, 40, 100);

	positionTexte.x = 40;
	positionTexte.y = 20;


    while (continuer)
    {
        SDL_Flip(SDL_GetVideoSurface());
        controleEvent = AttendreEvent(positionClic, touche);
        if(controleEvent == 2)
        {
            if(ToucheSpec(touche) == SDLK_ESCAPE)
                continuer = 0;
        }
        else
        {
            if(ClicDansGrille(grilleJoueur, positionClic))
            {
                coord = ClicCaseGrille(grilleJoueur, positionClic);
                caseGrille = Consulter(grilleJoueur, coord);
                if(caseGrille->etatCase == GRILLE_CASE_NORMAL)
                    grilleJoueur = SetEtatCase(grilleJoueur, coord, GRILLE_CASE_TOUCHE);
                else if(caseGrille->etatCase == GRILLE_CASE_TOUCHE)
                    grilleJoueur = SetEtatCase(grilleJoueur, coord, GRILLE_CASE_NORMAL);

                updateGrille(grilleJoueur, coord);
            }
        }
    }

    LibererGrille(grilleJoueur);

    free(touche);
    free(positionClic);
}




