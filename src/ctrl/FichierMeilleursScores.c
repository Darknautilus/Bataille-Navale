#include "FichierMeilleursScores.h"

#include "../ctrl/UtilsModel.h"

#include <stdio.h>
#include <stdlib.h>

int placeScoreTableau(Score* tabScores[], Score *score){

    int i = 0;

    //On recherche l'index où placer le score.
    //Le tableau de scores doit être trié par ordre décroissant.
    for (i = 0 ; i < MAX_MEILLEURS_SCORES ; i++){
        if(score->score > tabScores[i]->score){
            return i;
        }
    }

    //Si le score n'a pas sa place
    return -1;
}

void ajouterScore(Score *score){

    int i;
    int placeScore = 0;

    //on récupère le tableau des scores.
    Score* *tabScores = getMeilleursScoresFichier();

    //On récupère l'index où placer le score
    placeScore = placeScoreTableau(tabScores, score);

    //Pour libérer les ressources
    Score* dernierScore = NULL;

    //Si le score doit être placé
    if(placeScore >= 0){

        dernierScore = tabScores[MAX_MEILLEURS_SCORES-1];

        //On décale les autes scores
        for(i = MAX_MEILLEURS_SCORES-1; i > placeScore; i--){
            tabScores[i] = tabScores[i-1];
        }

        tabScores[i] = score;

        libererScore(dernierScore);
    }

    //on enregistre tout
    enregistrerTabScore(tabScores);

    //on libère le tableau des scores
    for(i = 0 ; i < MAX_MEILLEURS_SCORES ; i++){
        libererScore(tabScores[i]);
    }

    return;
}


Score** getMeilleursScoresFichier(){

    FILE* fichier = ouvrirFichierMeilleursScores("r");
    int i = 0;

    //Tableau dynamique de pointeur de Score
    Score* *tabScore = malloc( sizeof(Score*) * MAX_MEILLEURS_SCORES );

    for(i = 0 ; i< MAX_MEILLEURS_SCORES ; i++){
        tabScore[i] = malloc(sizeof(Score));
        fread(tabScore[i], sizeof(Score), 1, fichier);
    }

    fclose(fichier);

    return tabScore;
}

void enregistrerTabScore(Score* tabScores[]){

    //on ouvre le fichie ren écriture avec vidage préalable
    FILE* fichier = ouvrirFichierMeilleursScores("w+");

    int i;

    //On écrit tout les scores
    for(i = 0 ; i < MAX_MEILLEURS_SCORES ; i++){
        fwrite(tabScores[i], sizeof(Score), 1, fichier);
    }

    fclose(fichier);

    return;
}

FILE* ouvrirFichierMeilleursScores(const char modeOuverture[]){
    return ouvrirFichierRessources(FIC_MEILLEURSSCORES, modeOuverture);
}

