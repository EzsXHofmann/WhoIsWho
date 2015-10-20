# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "adaboost.h"

/* Algo de la video qui correspond + ou - 
 * a celui de Wikipedia (eng) 
 */
int adaboost(struct samples[], size_t len, size_t nbIter)
{   
    FILE *charFile = NULL; 
    double sampWeights[len];
    double weights = 1.0/len
    size_t nbCharacs = 162336; //Nombre théorique de caracs computed
    for(size_t i = 0; i < len; i++) //initialisation des poids
        sampWeights[i] = weights;

    /* Boucle principale ; nbIter = 
     * nombres de classificateurs faibles
     * utilisés pour construire le classifieur
     * fort */
    for(size_t t; t <= nbIter; t++) 
    {
       /* Normalisation des poids */
       double  weightSum = 0.0
       for(size_t i = 0; i < len; i++)
            weightSum += sampWeights[i];

       weights = weights / weightSum;
       /*Fin de la normalisation */
       
       /*Recuperation des features 
        * pour le classifieur faible */
       for(size_t i = 0; i < len; i++)
       {
            file = fopen(samples[i].filename,"r");
            if(file == NULL)
            {
                printf("Error opening %s file", samples[i].filename);
                return -1;
            }
            /* TODO 
             * Trouver le threshold (cf .h) qui minimise les erreurs
             * de classifications en appliquant 
             * chaque feature a chaque image 
             * pour trouver le classifieur faible avec
             * un taux d'erreur minimal (utiliser arg min)
             */
            

       }








    }

}
