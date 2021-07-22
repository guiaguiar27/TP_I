#include "../include/Buffer.h" 

void empity_buffer(Buffer *b, int id){ 
    b->head = (cell*)malloc(sizeof(cell)); 
    b->tail = b->head;  
    b->head->next = NULL; 
    b->id = id;  

}  
void enqueue(Buffer *b, char *data){ 
   cell *aux = (cell*)malloc(sizeof(cell)); 
   b->tail = aux;  
   b->tail->item.data = data; 
   b->tail->next = NULL; 
} 
void dequeue(Buffer *b){ 
    
}