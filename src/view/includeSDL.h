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






#endif
