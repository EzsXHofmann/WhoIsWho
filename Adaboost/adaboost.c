# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "adaboost.h"

# define T 20 //nb de classifieurs faibles dans un fort
# define NbFeatures 162336
# define MAXFEATVAL 1000000

double tabSum(double *tab, int len)
{
    double acc = 0;
    for(int i = 0; i < len; i++)
        acc += tab[i];
    return acc;
        
}

int getFeature(char *featFilePath, int featNumber)
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
    return res;

}

int testValue(int value, int threshold)
{
    if(value < threshold)
        return 0;
    else
        return 1; 
}

//somme de 1 à N
double computeSum(int *values, double *weights, Sample samples[],
                  int threshold,int N)
{
    double acc = 0.0;
    for(int i = 0; i < N; i++)
    {
        int tested = testValue(values[i],threshold);
        if(tested == samples[i].positive)
            tested = 0;
        else
            tested = 1;
        acc += weights[i]*(double)tested;
    }
    return acc;
}

// Trouve le seuil qui minimise l'erreur de classification
int findTreshold(int *values, double *weights, Sample samples[],
                 int N)
{
    
    int min = 2000000;
    //MAX* = valeur max possible du seuil
    for(int i = 0; i < MAXFEATVAL; i++)
    {
        double res = computeSum(values,weights,samples,i,N);
        if(res < min)
            min = i;
    }

    return min;

}

void AddClassifier(StrongClassifier sc, WeakClassifier wc)
{
    sc.wc[sc.count] = wc;
    sc.count++;
}

int adaBoost(Sample samples[], int nbPos, int nbNeg
            , StrongClassifier strong)
{
    int nbSamples = nbPos + nbNeg;
    double *weights = malloc(nbSamples * sizeof(double));
    int *usedFeature = malloc(nbSamples * sizeof(int));
    

    int i,j;

    //initialisation des poids
    for(i = 0; i < nbSamples; i++)
        if(samples[i].positive == 1)
            weights[i] = 1/nbPos;
        else
            weights[i] = 1/nbNeg;

    //Boucle principale (boosting)
    for(int t = 0; t < T; t++)
    {
        //Normalisation des poids
        int summedWeights = tabSum(weights, nbSamples);
        for(i = 0; i < nbSamples; i++)
            weights[i] /= summedWeights;
        
        //Fin de la normalisation des poids

        //Pour chaque feature on trouve train
        //un classifieur faible hj
        //On trouve ensuite le classifieur
        //Avec le taux d'erreur minimal
        WeakClassifier classifiers[NbFeatures];

        for(j = 0; j < NbFeatures; j++)
        {
            if(usedFeature[j])
                continue;
            
            int featValues[nbSamples];
            for(i = 0; i < nbSamples; i++)
                featValues[i] = getFeature(samples[i].filename, j);

            int treshold = findTreshold(featValues, weights, samples,
                                        nbSamples);
            double error = computeSum(featValues, weights, samples,
                                      treshold, nbSamples);

            classifiers[j].treshold = treshold;
            classifiers[j].error = error;
                  
        }

        //On cherche le classifieur avec le taux
        //d'erreur minimal
        double minError = classifiers[0].error;
        int minIndex = 0;
        int treshold = 0;

        for(j = 1; j < NbFeatures; j++)
        {
            if(classifiers[j].error < minError)
            {
                treshold = classifiers[j].treshold;
                minError = classifiers[j].error;
                minIndex = j;
            }
        }

       
        if(minError >= 1)
        {
            printf("minError >= 1 cant do log\n");
            return -1;
        }

        //Coefficients ...
        double beta = (1 - minError)/minError;
        double alpha = log(beta);

        WeakClassifier cls;
        cls.treshold = treshold;
        cls.error = minError;   
        cls.alpha = alpha;
        AddClassifier(strong,cls);
        usedFeature[minIndex] = 1;

        //Pondération des poids 
        //des exemples d'apprentissage            
        
        for(i = 0; i < nbSamples; i++)
        {
            int val = getFeature(samples[i].filename, minIndex);
            int e = testValue(val, treshold);

            if(e == samples[i].positive)
                e = 0;
            else
                e = 1;
            weights[i] *= pow(beta, (double)(1-e));          

        }

                  
    }
    
    //TODO
    //classifieur final h(x) x = ???

    free(weights);
    free(usedFeature);
    return 0;

}

int main()
{
    return 0;
}
