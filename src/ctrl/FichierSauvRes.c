/**
 * \file FichierSauvRes.c
 * \author Benoît Sauvère
 * \date 19/06/2012
 * \brief Controleur du fichier de sauvegarde
 *
 * Contient les implémentations des fonctions utilisées pour la sauvegarde et la restauration d'une partie.
*/

#include "FichierSauvRes.h"

#include "fichierDebug.h"

#include "../model/bateau.h"
#include "../model/grille.h"
#include "../model/partie.h"

int sauvegardePartie(TPartie *partie, const char nomSauv[]){

    FILE *fichier;
    char * chemin = malloc( sizeof(char) * (strlen("ressources/saves/") + strlen(nomSauv)));

    //Création du chemin
    strcpy(chemin, "ressources/saves/");
    strcat(chemin, nomSauv);

    //On ouvre le fichier en écrant tout le contenu
    fichier = fopen(chemin, "w+");

    if(ferror(fichier)){
        dgErreur("Impossible d'ouvrir le fichier de sauvegarde.");
        return 0;
    }
    else{
        //On sauvegarde tout

        //les bateaux
        sauvegardeBateaux(partie, fichier);

        //La grille du joueur
        sauvegardeGrilles(partie->grille, fichier);
        sauvegardeGrilles(partie->grilleMachine, fichier);

        //La grille de la machine
        sauvegardeCoups(partie, fichier);

        //Les paramètes
        sauvegardeParam(partie, fichier);

        fclose(fichier);

        return 1;
    }

}

int sauvegardeBateaux(TPartie *partie, FILE *fichier){

    int nbBateaux = getNbBat(partie->parametres);
    int i = 0;
    TBateau bat;

    //on écrit le nombre de bateaux par joueurs
    fwrite(&nbBateaux, sizeof(nbBateaux), 1, fichier);

    //On écrit tout les bateaux du joueur
    for(i = 0 ; i < nbBateaux ; i++){
        bat = *(partie->joueur->mesBateaux[i]);
        fwrite(&bat, sizeof(bat), 1, fichier);
    }

    //On écrit tout les bateaux de la machine
    for(i = 0 ; i < nbBateaux ; i++){
        bat = *(partie->machine->mesBateaux[i]);
        fwrite(&bat, sizeof(bat), 1, fichier);
    }

    fwrite(partie->joueur->nomJ, sizeof(partie->joueur->nomJ), 1, fichier);
    fwrite(partie->machine->nomJ, sizeof(partie->machine->nomJ), 1, fichier);

    return 1;
}

int sauvegardeGrilles(Grille *grille, FILE *fichier){

    int nbLigne, nbColonne, abs, ord;
    int i, j;
    Coord position;
    CaseGrille *caseGrille;

    nbLigne = grille->NbLin;
    nbColonne = grille->NbCol;
    abs = grille->abscisse;
    ord = grille->ordonnee;

    //On écrit le nombre de ligne et de colonne
    fwrite(&nbLigne, sizeof(nbLigne), 1, fichier);
    fwrite(&nbColonne, sizeof(nbColonne), 1, fichier);

    //On écrit le tableau des CaseGrilles
    //Ligne par ligne
    for(i = 1 ; i <= nbLigne ; i++){
        position.noLin = i;

        for(j = 1 ; j <= nbColonne ; j++){
            position.noCol = j;

            //On récupère la case et on l'écrit
            caseGrille = Consulter(grille, position);
            fwrite(caseGrille, sizeof(CaseGrille), 1, fichier);
        }
    }

    //On écrit l'abscisse et l'ordonnée
    fwrite(&abs, sizeof(abs), 1, fichier);
    fwrite(&ord, sizeof(ord), 1, fichier);

    return 1;
}

int sauvegardeCoups(TPartie *partie, FILE *fichier){

    //On compte le combre de coups dans la pile et on l'écrit
    int nbCoups = longueurPile(partie->pileCoups);

    Pile pile = partie->pileCoups;

    fwrite(&nbCoups, sizeof(nbCoups), 1, fichier);

    // on écrit les coups du sommet vers la queue
    while(pile != NULL){
        fwrite(&(pile->Info), sizeof(pile->Info), 1, fichier);
        pile = pile->Lien;
    }


    return 1;
}

int sauvegardeParam(TPartie *partie, FILE *fichier){

    int nbTypeInstances = K_NBTYPEBATEAUX;
    int nbTInfoBateau = getNbBat(partie->parametres);

    int i;

    //On écrit le nombre de type de bateaux
    fwrite(&nbTypeInstances, sizeof(nbTypeInstances), 1, fichier);

    //on écrit le tableau contenant le nombre de bateau pour chaque type
    for(i = 0 ; i < nbTypeInstances ; i++){
        fwrite(&(partie->parametres->nombreInstanceBateaux[i]), sizeof(int), 1, fichier);
    }

    //On écrit les TInfoBateau pour le joueur puis pour la machine
    //On sait que nb(TInfoBateau) = nb(Bateau d'un joueur)

    for(i = 0 ; i < nbTInfoBateau ; i++){
        fwrite(&(partie->parametres->bateauxJoueur[i]), sizeof(partie->parametres->bateauxJoueur[i]), 1, fichier);
    }

    for(i = 0 ; i < nbTInfoBateau ; i++){
        fwrite(&(partie->parametres->bateauxMachine[i]), sizeof(partie->parametres->bateauxJoueur[i]), 1, fichier);
    }


    return 1;
}
