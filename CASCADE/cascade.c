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

int sampleUp(StrongClassifier strong, Sample samples[], int nbPos, int nbNeg, 
int k)
{
    //Sample sam[] = sizeof(Sample) * (nbPos + nbNeg + 1);
    /*for (int i=1; i<=nbPos; i++)
    {
        sam[i] = samples[i];
    }*/
    int i = nbPos + 1;
    int j = 0;
    while (i < nbNeg + nbPos)
    {
        //printf("SAMPLEUP\n");
        if( applyStrongClassifier(strong, samples[i], k))
            nbNeg--;
        else
            samples[j++] = samples[i];
        i++;
    }
    //free (samples[])
    //samples[]=sam[];
    return nbNeg;
}


float rateSetter(StrongClassifier strong, Sample samples[], int nb, int nb2, int
j)
{
    float a = 0;
	int k;
    for (int i = 1; i <= nb; i++)
    {
        //printf("RATESETTER, %d, %d\n",i,nb);  
        k = applyStrongClassifier(strong, samples[i + nb2], j);
        a= ( a * i + k) / ( i + 1);
        printf("k, %d a, %f ,i %d \n",k,a,i);
    }
    return a;
}


void cascade (Sample samples[], int nbPos, int nbNeg, float f, float FTarget, float D)
{
    /* f correspond au nombre maximum de faux positif
     * FTarget est le nombre
     * D est le taux minimum de detection
     */
    int etape = 1;
    float FMinus, FCurrent, dMinus, d;
    FMinus = 1;
    dMinus = 0;
    // Initialisation des F(n-1), d(n-1), F(n) et d(n) 
    int nFeat = 2;
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
                        nFeat, 162336);
                //Operation taux de faux positif courrant
                d = rateSetter(strong, samples, nbPos, 0, 2);
                FCurrent = rateSetter(strong, samples, nbNeg, nbPos, 2);
                int j = 0;
                while(D * dMinus > d)
                {
                    printf("dMinus, %f d, %f\n",dMinus,d);
                    d = rateSetter(strong, samples, nbPos, 0, j++);
                    FCurrent = rateSetter(strong, samples, nbNeg, nbPos, j);
                }
                nbNeg = sampleUp(strong, samples, nbPos, nbNeg,  3);
                FMinus = FCurrent;
                dMinus = d;
            }while(FCurrent > f*FMinus);
            write(strong);
        }while(FCurrent > FTarget);
        write(strong);
    }
}

