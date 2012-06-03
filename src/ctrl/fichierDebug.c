/**
 *   \file fichieDebug.c
 *   \author Benoit Sauvere
 *   \date 03 juin 2012
 *   \brief Module Debug
 *
 *   Contient les impl�mentation des fonctions du module Debug.
*/

#include "fichierDebug.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

FILE* debug_file;
char debug_path[] = "Bataille-Navale.log";

int init_debug(){

    //Le resultat de la fonction
    int resultat = 0;

    //Pour r�cup�rer la date "locale"
    struct tm * localDate;
    time_t dateActuelle;

    //On r�cup�re la date courante
    dateActuelle = time (NULL);
    localDate = localtime (&dateActuelle);

    //On tente d'ouvrir le fichier ou seront marqu� les informations de debug.
    debug_file = fopen(debug_path, "w");

    //Si le fichier ne peut pas �tre cr�er
    if(debug_file == NULL){
        fprintf(stderr, "Attention : Impossible de creer le fichier de debug.");
        resultat = 1;
    }
    else{
        fprintf(debug_file, "====================== Debug BatailleNavale ======================\n");
        //On inscrit la date d'ex�cution
        fprintf(debug_file, "Date d'execution : %s\n", asctime (localDate));
    }

    return resultat;
}

int detruire_debug(){

    debug("", "Execution finished.");

    if(debug_file != NULL){
        fprintf(debug_file, "==================================================================");
    }

    fclose(debug_file);

    return 0;
}

//==============================================================================================================

int dgSDL (const char message[]){
    return debug("SDL : ", message);
}

int dgInfo (const char message[]){
    return debug("Info : ", message);
}

int dgAttention (const char message[]){
    return debug("Attention : ", message);
}

int dgErreur (const char message[]){
    return debug("Erreur : ", message);
}

int dgFatal (const char message[]){
    return debug("Erreur fatale : ", message);
}

int debug (const char prefixe[], const char message[]){

    //Pour r�cup�rer la date "locale"
    struct tm * localDate;
    time_t dateActuelle;
    int resultat;
    int tailleDate;

    char* messageFinal = NULL;
    char* messageDate = NULL;

    //Si l'on a pas d'erreur avec le fichier de debug
    if(!ferror(debug_file)){
        //On r�cup�re la date courante
        dateActuelle = time(NULL);
        localDate = localtime ( &dateActuelle );

        tailleDate = strlen(asctime(localDate));

        messageFinal = malloc(
                               sizeof(char) *
                              (strlen(message) + strlen(prefixe) + tailleDate + 2 + 1)
                              );

        messageDate = malloc(
                                sizeof(char) *
                                (tailleDate +1)
                             );


        //On supprime le \n � la fin du asctime(localDate)
        strcpy(messageDate, asctime(localDate));
        messageDate[tailleDate-1] = '\0';

        //On g�n�rele message final
        strcpy(messageFinal, "[");
        strcat(messageFinal, messageDate);
        strcat(messageFinal, "] ");
        strcat(messageFinal, prefixe);
        strcat(messageFinal, message);
        strcat(messageFinal, "\n");

        //On ecrit le message dans le fichier de debug
        if( !fprintf(debug_file, messageFinal) ){
            resultat = -1;
        }

        resultat = 0;
    }
    else{
        resultat = 1;
    }

    free(messageFinal);
    free(messageDate);

    return resultat;
}
