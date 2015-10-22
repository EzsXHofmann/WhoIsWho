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
       
            file = fopen(samples[0].filename,"r");
            if(file == NULL)
            {
                printf("Error opening %s file", samples[i].filename);
                return -1;
            }
            /* Un feature par itération */
            for(size_t j = 0; j < nbCharacs; j++)
            {
                char curFeat[10] = "";
                curFeat = fgets(curFeat,5,file);
                int feature = strtoul(curFeat,NULL,10);

                   
              
            }
                       

       
    }

}



double epsilon(int feat, int treshold, int positive)
{
  int eps = 0;
  if(weakClassifer(feat,threshold) != positive)
      eps = 1;
  return (double)epsilon; 
}


