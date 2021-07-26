#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
/**  
 * \file include/Buffer.h 
 * \brief Buffer struct and Buffer class implementation. 
 **/ 

typedef struct Fcell *Fpointer;

typedef struct Item {
  char  *data;
}Item;

typedef struct Fcell {
  Item item;
  Fpointer next; 
  int Position;
}Fcell;

typedef struct Buffer{
    Fpointer head, tail;  
    int size; 
    int id;
}Buffer;


/** 
 * \brief Buffer implementation.
 */ 
void empity_buffer(Buffer *b, int id );

void enqueue(Buffer *b, char *data); 

void dequeue(Buffer *b, Item *Item); 

void show(Buffer b);

void  move_to_front(Buffer *b, int position);
