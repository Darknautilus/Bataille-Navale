#include "model/Score.h"

#include <string.h>
#include <stdlib.h>

Score* creerScore(){
    return creerScoreP(0, "");
}

Score* creerScoreP(int score, const char nom[]){

    Score *nouvScore = malloc (sizeof(Score));

    nouvScore->score = score;

    strcpy(nouvScore->nom, nom);

    return nouvScore;
}

int getScore(Score *score){
    return score->score;
}

char* getNomScore(Score *score){
    return score->nom;
}

void setScore(Score *score, int nouvScore){
    score->score = nouvScore;
}

void setNomScore(Score *score, const char nouvNom[] ){
    strcpy(score->nom, nouvNom);
}

void libererScore(Score *score){
    free(score);
}
