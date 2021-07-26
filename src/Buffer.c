#include "../include/Buffer.h" 

/*  
* Cria um novo buffer 
*/
void empity_buffer(Buffer *b, int id ){  
    b->head = (Fpointer)malloc(sizeof(Fcell));  
    b->tail = b->head;
    b->head->next = NULL; 
    b->id = id; 
    b->size = 0; 
    b->head->Position = 0; 
    b->tail->Position = 0;
    //printf("Created a buffer %d\n",b->id);

}  
/* 
Enfileira o buffer   
*/ 
void enqueue(Buffer *b, char *data){  

    b->tail->next = (Fpointer)malloc(sizeof(Fcell));
    b->tail = b->tail->next; 
    
    b->tail->item.data = (char*)malloc(sizeof(char));
    strcpy(b->tail->item.data,data);  
    b->tail->next = NULL; 
    b->tail->Position = b->size; 
    b->size++; 
   
    

}  
/* 
Desenfileira o buffer   
*/ 


void dequeue(Buffer *b, Item *Item){  
    Fpointer aux;  
    aux = b->head; 
    // atencao aui caso a remocao não ocorra bem
    b->head = b->head->next; 
    *Item = b->head->item;
    b->size--;
    free(aux);     
    

    

} 
/* 
    Imprime a fila do buffer de um dado servidor  
    Cada fila pode conter diversas células.     
*/
void show(Buffer b){ 
    Fpointer aux;
    printf("Size: %d\n",b.size);
    
    aux = b.head->next;  

    while(aux!=NULL){  
        printf("Position: [%d] = %s\n",aux->Position,aux->item.data);
        aux = aux->next;
    }
    

} 
/* 
    Função utilizada no warning   
    coleta o item na ultima posição trocando com o item da primeira posição.  



*/
void  move_to_front(Buffer *b, int position){ 
    
    Fpointer Find = b->head->next;    
    Fpointer aux;  
    while(Find != NULL)  
    {  
        if(Find->Position == position) break;  
        Find = Find->next;
    } 

    aux = b->head;  
    Item *Item = &(b->head->item);
    b->head = Find;   
    enqueue(b,Item->data);  
    b->size -= 2; 
    free(Find);
    free(aux);    

    
   

}