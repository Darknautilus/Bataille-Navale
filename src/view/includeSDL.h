

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

    //Définis où se trouvent les ressources du programme
    #define RESSOURCES_REP "ressources"

    //Définis où se trouvent les polices d'écriture
    #define FONT_REP "ressources/Fonts/"    //Définis où se trouvent les images
    #define IMG_REP "ressources/Images/"

#endif
