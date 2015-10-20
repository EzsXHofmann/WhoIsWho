# ifndef _ADABOOST_ADABOOST_H
# define _ADABOOST_ADABOOST_H

struct samples
{
    char *filename; //Haar characs computed for the sample img
    int positive; // 0 if pos 1 if negative
}

inline
double weakClassifier(int x, double treshold)
{
    return (x < treshold)?0:1; 
}
int adaboost(struct samples[],size_t len, int nbIter); 



#endif

