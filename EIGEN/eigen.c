#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../DataBase/base.h"
#include "../SDLIMAGE/basic_fun.h"
#include "queue.h"

struct queue *keepeigens(EltDB *sent, int *cp)
{
  struct queue *q = queue_empty();
  EltDB *tmp = sent->next;


void mean_images(EltDB *elt)
{
  EltDB *tmp = elt->next;
  int eigens[elt->eigen][24][24];
  struct queue *q = queue_empty();
  char *path;
  int *array;
  int cp;

  while (tmp)
  {
    int a = tmp->eigen;
    cp = 0;

    while (tmp->eigen == a)
    {
      path = "../img/";
      array = image_to_intarray(strcat(path, tmp->name));
      queue_push(&q, array);
      tmp = tmp->next;
      cp++;
    }
    queue_push(&q, NULL);

    array = queue_pop(&q);


    for (int i = 0; i < 24; i++)
    {
      for (int j = 0; j < 24; j++)
      {
        while (array)
        {
          queue_push(&q, array);
          eigens[a][i][j] += *(array + i + j*24);
          array = queue_pop(&q);
        }
        queue_push(&q, NULL);
        eigens[a][i][j] /= cp;
      }
    }
  }

  free(eigens);
}

int *difference(int *img, int *mean)
{
  int *diff = malloc(576*sizeof(int));
  for (int j = 0; j < 24; j++)
    for (int i = 0; i < 24; i++)
      *(diff + j*24 + i) = *(img + j*24 + i) - *(mean + j*24 + i);
  
  return diff;
}
