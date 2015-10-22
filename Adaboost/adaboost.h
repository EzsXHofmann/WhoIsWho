# ifndef _ADABOOST_ADABOOST_H
# define _ADABOOST_ADABOOST_H

struct samples
{
    char *filename; //Haar characs computed for the sample img
    int positive; // -1 is not a face , 1 is a face 
}

inline
int weakClassifier(int x, int treshold)
{
    return (x < treshold)?1:-1; 
}
int adaboost(struct samples[],size_t len, int nbIter);
double epsilon(int feat, int threshold, int positive);




#endif

