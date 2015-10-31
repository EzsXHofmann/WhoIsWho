# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "adaboost.h"

int tabSum(int *tab, int len)
{
    int acc = 0;
    for(int i = 0; i < len; i++)
        acc += tab[i];
    return acc;
        
}

double getFeature(char *featFilePath, int featNumber)
{
    FILE *file = fopen(featFilePath, "r");
    if(file == NULL)
        return -1;
    char *s = malloc(10*sizeof(char));
    s = fgets(s,10,file);
    for(int i = 1; i < featNumber; i++)
    {
        s = fgets(s,10,file);
    }
    int res = atoi(s);
    free(s);
    s = NULL;
    return (double)res;

}

int adaBoost(Sample samples[], int nbPos, int nbNeg
            , StrongClassifier strong)
{
    int nbSamples = nbPos + nbNeg;
    int *sampleType = malloc(nbSamples * sizeof(int));
    int *weights = malloc(nbSamples * sizeof(int));
    int *usedFeature = malloc(nbSamples * sizeof(int));
    int i,j;

    for(i=0; i < nbPos; i++)
        sampleType[i] = 1;
    for(i = nbPos; i < nbSamples; i++)
        sampleType[i] = -1;

    //initialisation des poids
    for(i = 0; i < nbSamples; i++)
        if(sampleType[i] == 1)
            weights[i] = 1/nbPos;
        else
            weights[i] = 1/nbNeg;

    //Boucle principale (boosting)
    for(int t = 0; t < T; t++)
    {
        int minError = 0;
        int minIndex = 0;

        //Normalisation des poids
        int summedWeights = tabSum(weights, nbSamples);
        for(i = 0; i < nbSamples; i++)
        {
            weights[i] /= summedWeights;
        }
        //Fin de la normalisation des poids

        //Pour chaque feature on trouve train
        //un classifieur faible hj
        //On trouve ensuite le classifieur
        //Avec le taux d'erreur minimal
        WeakClassifer classifiers[nbFeatures];

        for(j = 0; j < NbFeatures; j++)
        {
            if(usedFeature[j])
                continue;
                 
           double *featValues = malloc(nbSamples * sizeof(double));
           for(i = 0; i < nbSamples; i++)
               featValues[i] = getFeature(samples[i].filename, j);

           

           
        }

        





    }


}
