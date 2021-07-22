
/**  
 * \file include/Buffer.h 
 * \brief Buffer struct and Buffer class implementation. 
 **/ 

typedef struct Item {
    char *data;
}Item; 
typedef struct cell{ 
    Item item; 
    cell *next;
} cell; 
typedef struct Buffer{ 
    cell *head; 
    cell *tail;  
}cell;

/** 
 * \brief Buffer implementation.
 */ 
void empity_buffer(Buffer *b);

void enqueue_buffer(Buffer *b); 

void dequeue_buffer(Buffer *b); 