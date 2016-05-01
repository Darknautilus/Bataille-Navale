/**
 * \file IncludeSDL.h
 * \author Aurélien Bertron
 * \date 19 juin 2012
 * \brief Vue Inclusion de la SDL
 *
 *  Contient les inclusions nécessaires à l'utilisation de la libraire SDL,
 *  ainsi que les chemins vers plusieurs dossiers de ressources.
*/

#ifndef INCLUDE_SDL_H
#define INCLUDE_SDL_H


    //Inclusion pour Windows
    #if defined (__WIN32__)

        #include <SDL.h>
        #include <SDL_image.h>
        #include <SDL_ttf.h>

    //Inclusion pour les autres systèmes
    #else

        #include <SDL2/SDL.h>
        #include <SDL2/SDL_image.h>
        #include <SDL2/SDL_ttf.h>

    #endif

    /**<Définis où se trouvent les ressources du programme**/
    #define RESSOURCES_REP "ressources/"

    /**<Définis où se trouvent les polices d'écriture du programme**/
    #define FONT_REP "ressources/Fonts/"

    /**<Définis où se trouvent les images du programme**/
    #define IMG_REP "ressources/Images/"
#endif
