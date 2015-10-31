# ifndef _ADABOOST_H_
# define _ADABOOST_H_

# define T = 20 //nb de classifieurs faibles dans un fort
# define NbFeatures = 162341
typedef struct
{
    char *filename; //Haar characs computed for the sample img
    int positive; // -1 is not a face , 1 is a face 
} Sample
typedef struct
{
    double treshold;
    double alpha;
    double error;
    int positive;
    int *features;

} WeakClassifier
typedef struct 
{
    double error;
    int acc;
    WeakClassifier sc[25];

} StrongClassifier
    



#endif

