typedef 
	struct {
		void * buffer ;
		int unit;

		int front;
		int rear;
		
		int capacity ;
		int size ;
	} 
	queue_t ;

queue_t * 
create_queue (int capacity, int unit) ;

void
delete_queue (queue_t * queue) ;

int 
enqueue (queue_t * queue, void * elem) ;

int
dequeue (queue_t * queue, void * elem) ;

int
front (queue_t * queue, void * elem) ;

int 
is_empty (queue_t * queue) ;

int 
is_full (queue_t * queue) ;

int
get_size (queue_t * queue) ;

int 
get_elem (queue_t * queue, int i, void * elem) ;