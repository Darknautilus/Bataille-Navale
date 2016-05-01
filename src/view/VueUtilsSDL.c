#include "view/VueUtilsSDL.h"

#include "ctrl/UtilsSDL.h"
#include "ctrl/UtilsPoliceEcriture.h"
#include "view/IncludeSDL.h"
#include "view/SDLImage.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void ecrireTexte(char * texte, int taille, SDL_Rect positionTexte, char * cheminPolice)
{
    int longTexte = strlen(texte);
    char * nouvTexte = malloc((longTexte+1)*sizeof(char)); // chaine de travail

    int i = 0;

    // On initialise la chaine de travail
    strcpy(nouvTexte, "");

    // On parcourt la chaine principale caractère par caractère
    while(texte[i] != '\0')
    {
        // Si c'est un saut de ligne, on écrit la ligne et on passe à la suivante
        if(texte[i] == '\n')
        {
            ecrireLigneTexte(nouvTexte, taille, positionTexte, cheminPolice);
            positionTexte.y += taille;
            strcpy(nouvTexte, "");
        }
        // Sinon, on ajoute le caractère à la chaine de travail (ligne en cours)
        else
        {
            char *tmpP = nouvTexte;
            while(*tmpP) tmpP++;
            *tmpP = texte[i];
            *(++tmpP) = '\0';
        }

        // On passe au caractère suivant et si l'on est à la fin, on écrit la ligne.
        i++;
        if(texte[i] == '\0')
            ecrireLigneTexte(nouvTexte, taille, positionTexte, cheminPolice);
    }

    // Libération chaine de travail
    free(nouvTexte);
}

void ecrireLigneTexte(char * texte,int taille, SDL_Rect positionTexte, char * cheminPolice)
{
	SDL_Surface * zoneTexte;
	TTF_Font * police = chargerPoliceEcriture(cheminPolice, taille);
	SDL_Color couleur = {255,255,255};

	zoneTexte = TTF_RenderUTF8_Blended(police, texte, couleur);
	SDL_BlitSurface(zoneTexte, NULL, GetMainScreen(), &positionTexte);
	SDL_FreeSurface(zoneTexte);

	TTF_CloseFont(police);
}

int attendreEvent(SDL_Rect *coordClic, SDL_Keysym *touche)
{
    SDL_Event event;
    int continuer = 1;
    int controle = 0;  // Permet de retourner si l'événement est un clic ou une touche

    if (coordClic == NULL && touche == NULL) return 0;

    while(continuer)
    {
        if (SDL_PollEvent(&event)) {
            // Si c'est un clic gauche et qu'on a activé l'option
            if (event.type == SDL_MOUSEBUTTONDOWN && coordClic != NULL && event.button.button == SDL_BUTTON_LEFT)
            {
                coordClic->x = event.button.x;
                coordClic->y = event.button.y;
                controle = 1;
                continuer = 0;
            }
            // Si c'est une touche et qu'on a activé l'option
            else if(event.type == SDL_KEYDOWN && touche != NULL)
            {
                *touche = event.key.keysym;
                controle = 2;
                continuer = 0;
            }
            // Si l'utilisateur veut quitter brutalement
            else if(event.type == SDL_QUIT) {
                exit(EXIT_FAILURE);
            }
        }
    }

    return controle;
}

Uint32 convertSDL_Color(SDL_Color pCouleur)
{
    return SDL_MapRGB(GetMainScreen()->format, pCouleur.r, pCouleur.g, pCouleur.b);
}

void afficherCoordClic(SDL_Rect * pPosClic, int pTaille, int pAbs, int pOrd, char * pPolice)
{
    SDL_Rect posTexte;
    char texte[25];

    sprintf(texte, "x : %d ; y : %d", pPosClic->x, pPosClic->y);

    posTexte.x = pAbs;
    posTexte.y = pOrd;
    ecrireLigneTexte(texte, pTaille, posTexte, pPolice);
}

void pause(void)
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

void effacerEcran(void)
{
    ClearWindow();
}
