#include "ctrl/UtilsSDL.h"

#include "view/IncludeSDL.h"

#include <stdio.h>
#include <stdlib.h>

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    SDL_Surface_RGBA_Masks rgbaMasks = {0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff};
#else
    SDL_Surface_RGBA_Masks rgbaMasks = {0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000};
#endif

SDL_Surface *mainScreen = NULL;
SDL_Texture *mainTexture = NULL;
SDL_Renderer *mainRenderer = NULL;

SDL_Surface *GetNewRGBASurface(int width, int height) {
    return SDL_CreateRGBSurface(0, width, height, 32, rgbaMasks.rmask, rgbaMasks.gmask, rgbaMasks.bmask, rgbaMasks.amask);
}

SDL_Surface *GetMainScreen() {
    return mainScreen;
}

SDL_Texture *GetMainTexture() {
    return mainTexture;
}

void UpdateWindow(int reset) {
    SDL_UpdateTexture(mainTexture, NULL, mainScreen->pixels, mainScreen->pitch);
    if (reset == SDL_TRUE) {
        SDL_FillRect(mainScreen, NULL, SDL_MapRGB(mainScreen->format, 0, 0, 0));
    }
    SDL_RenderClear(mainRenderer);
    SDL_RenderCopy(mainRenderer, mainTexture, NULL, NULL);
    SDL_RenderPresent(mainRenderer);
}

void ClearWindow() {
    SDL_SetRenderDrawColor(mainRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mainRenderer);
    SDL_RenderPresent(mainRenderer);
}

void demarrerSDL(int width, int height, char * titreFenetre)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr,
            "\nUnable to initialize SDL:  %s\n",
            SDL_GetError()
            );
        exit(1);
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "\nUnable to initialize SDL_ttf\n");
        SDL_Quit();
    }
    atexit(arreterSDL);
    
    SDL_Window *mainWindow = SDL_CreateWindow(titreFenetre, 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        0, 0,
        SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (mainWindow == NULL) {
        fprintf(stderr,
            "\nUnable to create main window:  %s\n",
            SDL_GetError()
            );
        SDL_Quit();
    }
    
    mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);
    if (mainWindow == NULL) {
        fprintf(stderr,
            "\nUnable to create renderer:  %s\n",
            SDL_GetError()
            );
        SDL_Quit();
    }
    
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
    SDL_RenderSetLogicalSize(mainRenderer, width, height);
    
    ClearWindow();
    
    mainScreen = SDL_CreateRGBSurface(0, width, height, 32,
        0x00FF0000,
        0x0000FF00,
        0x000000FF,
        0xFF000000);
    mainTexture = SDL_CreateTexture(mainRenderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        width, height);
}

void arreterSDL(void)
{
    TTF_Quit();// On n'écrit plus
    SDL_Quit();// On ne voit plus
}
