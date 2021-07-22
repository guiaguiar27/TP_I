#include <stdio.h> 
#include <stdlib.h> 

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
    int id; 
    cell *head; 
    cell *tail;  
}Buffer;

/** 
 * \brief Buffer implementation.
 */ 
void empity_buffer(Buffer *b, int id);

void enqueue_buffer(Buffer *b, char *data); 

void dequeue_buffer(Buffer *b); 