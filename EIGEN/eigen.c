#include "../DataBase/base.h"
#include "queue.h"


void mean_image(EltDB *elt)
{
  EltDB *tmp = elt;
  struct queue *q = queue_empty();
  
  while (tmp)
  {
    int a = tmp->eigen;
    while (tmp->eigen == a)
      queue_push(&q, tmp);
    queue_push(&q, NULL);
    
    for (int i = 0; i < 24; i++)
      for (int j = 0; j < 24
