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
    b->head = b->head->next; 
    *Item = b->head->item;
    b->size--;
    free(aux); 

  

    

} 
/* 
    Imprime a fila do buffer de um dado servidor  
    Cada fila pode conter diversas células.  
    Exibe o tamanho das filas    
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
Exibe o conteudo dos buffers sem informações adicionais  
*/
void show_buffer(Buffer b){  

    Fpointer aux;
    aux = b.head->next;  
    while(aux!=NULL){  
        printf("%s\n",aux->item.data);
        aux = aux->next;
    }
}
/* 
    Função utilizada no warning   
    coleta o item na ultima posição trocando com o item da primeira posição.  
    Apenas copia o conteudo das celulas, não trabalha nos ponteiros
*/ 

void  move_to_front(Buffer *b, int position){ 
    
    Fpointer Find = b->head->next;    
    char *aux = (char*)malloc(sizeof(char)); 
    while(Find != NULL)  
    {  
        if(Find->Position == position) break;  
        Find = Find->next;
    }   

    strcpy(aux,b->head->next->item.data);
    printf("%s",aux);
    strcpy(b->head->next->item.data,Find->item.data);
    strcpy(Find->item.data,aux);   
   
    
    
   

}