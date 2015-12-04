#include "queue.h"

void queue_push(struct queue **q, void *p)
{
	struct queue *new = malloc(sizeof(struct queue));
  new->val = p;

  if (*q)
  {
  	new->next = (*q)->next;
    (*q)->next = new;
  }
  else
    new->next = new;

		*q = new;
}

void* queue_pop(struct queue **q)
{
	struct queue *temp = NULL;

  if (*q)
  {
    temp = (*q)->next;
 
    if ((*q)->next == temp->next)
    	*q = NULL;
    else
      (*q)->next = temp->next;
	}

  return temp->val;
}

