#include "../include/Buffer.h" 

void empity_buffer(Buffer *b, int id){ 
    b->head = (Fpointer)malloc(sizeof(Fcell)); 
    b->tail = b->head;  
    b->head->next = NULL; 
    b->id = id;  
    b->size = 0; 
}  
void enqueue(Buffer *b, char *data){ 
    Fpointer aux = (Fpointer)malloc(sizeof(Fcell)); 
    b->tail = aux;  
    b->tail->item.data = data; 
    b->tail->next = NULL; 
    if(b->tail != NULL){ 
        b->tail->Position = b->size; 
        b->size++; 
    }     
}  


Item  *dequeue(Buffer *b){  
    Item *remove = (Item*)malloc(sizeof(Item));  
    Fpointer aux;  
    aux = b->head; 
    // atencao aui caso a remocao não ocorra bem
    b->head = b->head->next;   
    *remove = b->head->item; 
    free(aux);    
    return remove; 
}