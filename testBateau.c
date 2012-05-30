#include "testBateau.h"

/**
    Test unitaire de la fonction estCoule.
    \return 1 si tout les test sont passé. 0 Si echec.
*/
int testEstCoule(){

    TPosition pos;
    int resultat = 1;

    //On créer un remorqueur (2 cases)
    TBateau *bat = creerBateau(pos, REMORQUEUR);

    if(estCoule(bat)){
        resultat = 0;
        printf("[NOK] Le bateau est coule a l'initialisation.");
    }

    //=======================================================

    //On le marque touché à la case 1
    bat->etat[0] = 1;

    printf("\n");

    if(estCoule(bat)){
        resultat = 0;
        printf("[NOK] Le bateau est coule avec une case sur deux touchee.");
    }

    //=======================================================

    //On le marque touche à la case 2 aussi.
    //ici le bateau deviens coulé.
    bat->etat[1] = 1;

    printf("\n");

    if(!estCoule(bat)){
        resultat = 0;
        printf("[NOK] Le bateau n'est pas coule avec toute les cases touchees.");
    }

    printf("\n");

    return resultat;
}

/**
    Test unitaire de la fonction estCoule.
    \return 1 si tout les test sont passé. 0 Si echec.
*/
int testCreerBateau(){

    TPosition pos;
    int i = 0;
    int resultat = 1;
    int type = REMORQUEUR;

    pos.x=99;
    pos.y=22;

    TBateau* bat = creerBateau(pos, type);

    //=================================================

    //Vérification que les positions sont correctes
    if(bat->position.x != 99 || bat->position.y != 22){
        printf("[NOK] Positions invalides.\n");
        resultat = 0;
    }

    //=================================================

    //Vérification que le type correspond
    if(bat->type != type){
        printf("[NOK] Type invalide.\n");
        resultat = 0;
    }

    //================================================

    //Toute les cases du tableau état doivent être à INTACT
    for(i = 0 ; i < type ; i++){

        if(bat->etat[i] != INTACT){
            printf("[NOK] Case %d pas INTACT.\n", i);
            resultat = 0;
        }

    }

    //================================================

    return resultat;

}


/**
    Test unitaire de la fonction toucheBateau.
    \return 1 si tout les test sont passé. 0 Si echec.
*/
int testToucheBateau(){

    TPosition pos;
    int type = PORTEAVION;
    int resultat = 1;
    int i;

    pos.x=99;
    pos.y=22;

    TBateau *bat = creerBateau(pos, type);

    //=================================================

    //On marque la case 1 comme touchée
    toucherBateau(bat, 1);

    if(bat->etat[0] != TOUCHE){
        printf("[NOK] Case non touchee.\n");
        resultat = 0;
    }

    //=================================================

    //On touche les autres cases
    for(i = 2 ; i <= type ; i++){
        toucherBateau(bat, i);
    }

    for(i = 0 ; i < type ; i++){

        if(bat->etat[i] != COULE){
            printf("[NOK] Case %d non coule.\n", i);
            resultat = 0;
        }

    }

    //=================================================

    return resultat;
}

/**
    Test unitaire des fonctions getPosBateau, getPosXBateau, getPosYBateau).
    \return 1 si tout les test sont passé. 0 Si echec.
*/
int testGetPosBateau(){

    int resultat = 1;
    int i;
    int type = REMORQUEUR;

    TPosition pos;

    pos.x=99;
    pos.y=22;

    TBateau *bat = creerBateau(pos, type);

    if(getPosBateau(bat).x != 99 || getPosBateau(bat).y != 22){
        printf("[NOK] Erreur dans les valeurs retournees par getPosBateau.");
        resultat = 0;
    }

    //=================================================

    if(getPosXBateau(bat) != 99){
        printf("[NOK] Erreur dans la valeur retournee par getPosXBateau.");
        resultat = 0;
    }

    //=================================================

    if(getPosYBateau(bat) != 22){
        printf("[NOK] Erreur dans la valeur retournee par getPosYBateau.");
        resultat = 0;
    }

    return resultat;
}
