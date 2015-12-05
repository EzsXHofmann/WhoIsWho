# ifndef QUEUE_H_
# define QUEUE_H_

struct queue 
{
   void *val;
   int eigen;
   struct queue *next;
};

static inline
struct queue* queue_empty() { return NULL; }

static inline
int queue_is_empty(struct queue *q) { return q == NULL; }

void queue_push(struct queue **q, void *p);

void* queue_pop(struct queue **q);

# endif
