#include "../include/Buffer.h" 

void empity_buffer(Buffer *b, int id){  
    
    //printf("Open buffer!\n");
    b->head = (Fpointer)malloc(sizeof(Fcell)); 
    b->tail = b->head;  
    b->head->next = NULL; 
    b->id = id;  
    b->size = 0; 
}   

void enqueue(Buffer *b, char *data){  
    //printf("Enqueue in buffer\n");
    Fpointer aux = (Fpointer)malloc(sizeof(Fcell)); 
    b->tail = aux;   
    b->tail->item.data = (char *)malloc(sizeof(char));
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

void show(Buffer *b){ 
    Fpointer aux;
    printf("Buffer: %d\n",b->id);
    printf("Size: %d\n",b->size);
    printf("\n");
    aux = b->tail;
    while(aux!=NULL){ 
        puts(aux->item.data);
        aux = aux->next;
    }

}