#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
/**  
 * \file include/Buffer.h 
 * \brief Buffer struct and Buffer class implementation. 
 **/ 

typedef struct Item{
    char *data;
}Item;  

typedef struct Fcell *Fpointer;  
typedef struct Fcell{ 
    Item item; 
    Fpointer next; 
    int Position;
}Fcell;  

typedef struct {  
    int id; 
    Fpointer head; 
    Fpointer tail;   
    int size; 
}Buffer;   




/** 
 * \brief Buffer implementation.
 */ 
void empity_buffer(Buffer *b, int id);

void enqueue(Buffer *b, char *data); 

Item  *dequeue(Buffer *b); 

void show(Buffer *b);