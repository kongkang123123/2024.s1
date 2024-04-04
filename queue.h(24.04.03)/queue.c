#include <stdlib.h>
#include "queue.h"

queue_t * 
create_queue (int capacity) 
{
	queue_t * queue = (queue_t *) malloc(sizeof(queue_t)) ;
    queue->front = 0;
    queue->rear = 0;
	queue->capacity = capacity ;
	queue->size = 0 ;
	queue->buffer = (int *) calloc(capacity, sizeof(int)) ;
	return queue ; 
}

void
delete_queue (queue_t * queue) 
{
	if (queue->buffer) {
		free(queue->buffer) ;
	}
	free(queue) ;
}

int 
enqueue (queue_t * queue, int elem)
{
	if (is_full(queue))
		return 0 ;
	
	queue->buffer[queue->rear] = elem ;
    // queue->rear += 1;
    // if(queue->rear == queue->capacity){
    //    queue->rear = 0;
    // }
    queue->rear = (queue->rear +1) % queue->capacity;
    queue->size +=1;
	return 1 ;
}

int
dequeue (queue_t * queue, int * elem)
{
	if (is_empty(queue)) 
		return 0 ;
	
	*elem = queue->buffer[queue->front] ;
	queue->front = (queue->front +1) % queue->capacity;
	
	queue->size -= 1 ;
	return 1;
}

int 
front (queue_t * queue, int * elem)
{
	if (is_empty(queue)) {
		return 0 ;
    }
	*elem = queue->buffer[queue->front] ;
	return 1;
}

int 
is_empty (queue_t * queue) 
{
	return (queue->size == 0) ;
}

int 
is_full (queue_t * queue) 
{
	return (queue->size == queue->capacity) ;
}

int
get_size (queue_t * queue) 
{
	return queue->size ;
}

int
get_elem (queue_t * queue, int i, int * elem)
{
	if (queue->front < 0)
		return 0 ;
	if (queue->size <= i)
		return 0 ;

	*elem = queue->buffer[(queue->front+i) % (queue->capacity)] ;
	return 1 ;
}