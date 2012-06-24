

#ifndef INCLUDE_SDL_H
#define INCLUDE_SDL_H


    //Inclusion pour benoit
    #if defined (__WIN32__)

        #include <SDL/SDL.h>
        #include <SDL/SDL_image.h>
        #include <SDL/SDL_ttf.h>

    #else

        #include <SDL/SDL.h>
        #include <SDL_image/SDL_image.h>
        #include <SDL_ttf/SDL_ttf.h>

    #endif

    #include <string.h>

    //DÈfinis o˘ se trouvent les ressources du programme
    #define RESSOURCES_REP "ressources/"

    //DÈfinis o˘ se trouvent les polices d'Ècriture
    #define FONT_REP "ressources/Fonts/"    //DÈfinis o˘ se trouvent les images
    #define IMG_REP "ressources/Images/"

#endif
