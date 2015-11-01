# ifndef _ADABOOST_H_
# define _ADABOOST_H_

#include <math.h>
typedef struct
{
    char *filename; //Haar characs computed for the sample img
    int positive; // 0 is not a face , 1 is a face 
} Sample;
typedef struct
{
    int treshold;
    double alpha;
    double error;

} WeakClassifier;
typedef struct 
{
   // double value;
    int count;
    WeakClassifier wc[25];

} StrongClassifier;
    
double tabSum(double *tab, int len);
int getFeature(char *featFilePath, int featNumber);
int testValue(int value, int threshold);
double computeSum(int *values, double *weights, Sample samples[],
                  int threshold,int N);
int findTreshold(int *values, double *weights, Sample samples[],
                 int N);
void AddClassifier(StrongClassifier sc, WeakClassifier wc);
int adaBoost(Sample samples[], int nbPos, int nbNeg
            , StrongClassifier strong);




#endif

