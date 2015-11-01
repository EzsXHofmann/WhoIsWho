#include<stdlib.h>
# include<stdio.h>
# include<err.h>


# include<string.h>
# include<assert.h>
# include<maths.h>
# include<float.h>
# include<assert.h>
# include<time.h>
# include<ctype.h>

# include"cls.h"



/*// TOUT CE QUI N'EST PAS INITIALISÉ EST ARBITRAIRE !
int cascade()    //Prend une image ou un tableau, on verra
{
    int f2;  //f_i+1
    int d2;  //d_i+1
    CalculCaractéristique(f2,d2,i,j);
    int f=f2;
    int d=d2;
    int i=1;
    while(i<K&& d>D)  //K=nombre d'étage choisi D=taux min de détection
    {
        int j=0;
        while(f<F)     //F=taux de fausse alarme max
        {  
            CalculCaractéristique(f2,d2,i,j++);  //Calcul en ajoutants le caractéristique j de complexité/détection i;  f2 et d2 en global
            d*=d2;
            f*=f2;
            j++;
        }

    }
    return d>D;
} */


void cascade (Sample samples[], int nbPos, int nbNeg, int f, int FTarget, int D)
{
    int FMinus, FCurrent, dMinus, d;
    FMinus=1;
    int nFeature=1;
    while (FCurrent> FTarget)
    {
        
        FCurrent=FMinus;
        while(Fcurrent>f*FMinus)
        {
            nFeature++;
            //StrongClassifier strong with n[j] feature;
            adaboost(sample[], nbPos, nbMin,strong);
            //Operation FCurrent, d;
            while(D*dMinus<d)
            {
                //Decrease threshold
            }
        }
    }
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
