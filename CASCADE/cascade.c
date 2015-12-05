#include<stdlib.h>
# include<stdio.h>
# include<err.h>
# include "../Adaboost/adaboost.h"
# include "cascade.h"


void swap2 (Sample *a, Sample *b)
{
    Sample c = *a;
    *a = *b;
    *b = c;
}

void write(StrongClassifier strong)
{
    FILE *f = fopen("SClist", "a");
    for(int i = 0; i < strong.count; i++) 
    {
        fprintf(f," WEAK CLASSIFIER %d :\nINDEX : %d\nERROR :%f\nTHRESHOLD :%d\n ALPHA     : %f\n\n ",i,
        strong.wc[i].index,strong.wc[i].error,
        strong.wc[i].treshold,
        strong.wc[i].alpha);
        fprintf(f,"---------------------------------------\n");
    }
    fclose(f);
}

int sampleUp(StrongClassifier strong, Sample samples[], int nbPos, int nbNeg)
{
    int i = nbPos;
    while (i < nbNeg + nbPos)
    {
        if( applyStrongClassifier(strong, samples[i]))
        {
            nbNeg--;
            swap2(&samples[i], &samples[nbPos + nbNeg]);
        }
        i++;
    }
    return nbNeg;
}


float rateSetter(StrongClassifier strong, Sample samples[], int nb, int nb2)
{
    float a = 0;
	int k;
	nb++;
    for (int i = 0; i < nb; i++)
    {
        k = applyStrongClassifier(strong, samples[i+nb2]);
        a= ( a * i + k) / ( i + 1);
    }
    return a;
}


void cascade (Sample samples[], int nbPos, int nbNeg, float f, float FTarget, float D)
{
    /* f correspond au nombre maximum de faux positif
     * FTarget est le nombre
     * D est le taux minimum de detection
     */
    int etape = 2;
    float FMinus, FCurrent, dMinus, d;
    FMinus = 1;
    dMinus = 0;
    // Initialisation des F(n-1), d(n-1), F(n) et d(n) 
    int nFeat = 1;
    for (int i = 0; i < etape; i++)
    {
       StrongClassifier strong; 
       do 
        {
            FCurrent = FMinus;
            do
            {
                nFeat++;
                //StrongClassifier strong with n[j] feature;
                strong = adaBoost(samples, nbPos, nbNeg, 
                        nFeat*2, nFeat*2);
                //Operation taux de faux positif courrant
                d = rateSetter(strong, samples, nbPos, 0);
                FCurrent = rateSetter(strong, samples, nbNeg, nbPos);

                while(D * dMinus > d)
                {
                    strong.wc->treshold/=2;
                    d = rateSetter(strong, samples, nbPos, 0);
                    FCurrent = rateSetter(strong, samples, nbNeg, nbPos);
                }
                nbNeg = sampleUp(strong, samples, nbPos, nbNeg);
                FMinus = FCurrent;
                dMinus = d;
            }while(FCurrent > f*FMinus);
            write(strong);
        }while(FCurrent > FTarget);
        write(strong);
    }
}

