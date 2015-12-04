#ifndef BASE_H_
#define BASE_H_

#include "../Adaboost/adaboost.h"

typedef struct EltDB
{
    int eigen;
    char *name;
    struct EltDB *next;
    struct EltDB *old;
    
} EltDB;

void initializeEltDB(EltDB *begin);

#endif
