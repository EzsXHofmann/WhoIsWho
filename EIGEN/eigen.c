#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../DataBase/base.h"
#include "../SDLIMAGE/basic_fun.h"
#include "eigen.h"

int *mean_image(EltDB *elt, int *mean)
{
  EltDB *tmp = elt->next;
  int *set = malloc(elt->eigen*576*sizeof(int));
  char *path;
  int *array;
  int cp = 0;

  while (tmp)
  {
    path = "../img/";
    array = image_to_intarray(strcat(path, tmp->name));
    
    for (int j = 0; j < 24; j++)
      for (int i = 0; i < 24; i++)
        *(set + cp*576 + j*24 + i) = *(array + j*24 + i);

    tmp = tmp->next;
    cp++;
  }

  for (int j = 0; j < 24; j++)
  {
    for (int i = 0; i < 24; i++)
    {
      *(mean + j*24 + i) = 0;
      for (int k = 0; k < cp; k++)
        *(mean + j*24 + i) += *(set + k*576 + j*24 + i);

      *(mean + j*24 + i) /= cp;
    }
  }

  return set;
}

void difference(int *set, int *mean, int nb)
{
  for (int j = 0; j < 24; j++)
    for (int i = 0; i < 24; i++)
      for (int k = 0; k < nb; k++)
        *(set + k*576 + j*24 + i) = *(set + k*576 + j*24 + i) - *(mean + j*24 + i);
}

/*int *transposee(int *set, int nb)
{
  int *trans = malloc(nb*576*sizeof(int));
  for (int j = 0; j < 24; j++)
    for (int i = 0; i < 24; i++)
      for (int k = 0; k < nb; k++)
        *(trans + k*576 + j*24 + i) = *(trans + k*56 + i*24 + j);

  return trans;
}*/

int *covariance(int *set, int nb)
{
  int *covar = malloc(nb*576*sizeof(int));

  for (int j = 0; j < 24; j++)
    for (int i = 0; i < 24; i++)
    {
      for (int k = 0; k < nb; k++)
        for (int l = 0; l < 24; l++)
          *(covar + j*24 + i) += pow(*(set + k*576 + j*24 + i + l), 2);
      *(covar + j*24 + i) /= nb;
    }

  return covar;
}

int main()
{
  return 0;
}
