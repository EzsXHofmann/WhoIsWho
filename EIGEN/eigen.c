#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../DataBase/base.h"
#include "../SDLIMAGE/basic_fun.h"
#include "queue.h"

void mean_images(EltDB *elt)
{
  EltDB *tmp = elt->next;
  int eigens[elt->eigen][24][24];
  struct queue *q = queue_empty();
  char *path;
  int *array;

  while (tmp)
  {
    int a = tmp->eigen;
      
    while (tmp->eigen == a)
    {
      path = "../img/";
      array = image_to_intarray(strcat(path, tmp->name));
      queue_push(&q, array);
      tmp = tmp->next;
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
        eigens[a][i][j] /= 3;
      }
    }
  }
}
