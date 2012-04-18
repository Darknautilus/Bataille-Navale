#include "util.h"

void initRandom(void)
{
     time_t t1;
     time (&t1);
     srand(t1);
}




int initConsoleJeu()
{

    LPSTR titre = "BATAILLE NAVALE";
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD tailleBuffer = {1000,500} ;
    SMALL_RECT fenetre  ;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo ;

    // Obtenir les informations de la console
     GetConsoleScreenBufferInfo(console, &csbiInfo)  ;

    // Adapter le buffer de la console en fonction des tailles maximales
    SetConsoleScreenBufferSize(console, tailleBuffer) ;

    // Modifier la taille de la console

    fenetre = csbiInfo.srWindow ;
    fenetre.Right = tailleBuffer.X - 1 ;
    fenetre.Bottom = tailleBuffer.Y - 1 ;
    SetConsoleWindowInfo(console, TRUE, &fenetre) ;

    SetConsoleTitleA(titre);
}
