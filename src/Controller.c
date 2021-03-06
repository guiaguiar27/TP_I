#include "../include/Controller.h"  


/* 
Executa o comando de info  
*/
void info(int server, char *data,Server *S){   
    Tpointer Aux = find_node(server,S);
     
    enqueue(&(Aux->Intern_Buffer),data);    
    #if DEBUG 
        printf("INFO\n");
        printf("Buffer id:%d\n",Aux->Intern_Buffer.id);  
        show(Aux->Intern_Buffer);
    #endif
} 
/* 
    Executa o comando de warn  
*/ 
void warn(int server, int position, Server *S){  
    
    Tpointer aux = find_node(server,S);   
    #if DEBUG
        puts("WARN");
        show(aux->Intern_Buffer); 
    #endif 
    move_to_front(&(aux->Intern_Buffer),position); 
    #if DEBUG 
        show(aux->Intern_Buffer); 
    #endif
} 
/* 
    Executa o comando de tran  
*/
void tran(int server_1, int server_2,Server *S){ 
    Tpointer aux1 = find_node(server_1,S); 
    Tpointer aux2 = find_node(server_2,S); 

    int tam = aux1->Intern_Buffer.size; 
    Item *item = (Item*)malloc(sizeof(Item));
    
    for(int i = 0; i < tam; i++){  
        dequeue(&(aux1->Intern_Buffer),item);  
        enqueue(&(aux2->Intern_Buffer),item->data);  
    }  
    #if DEBUG 
        show(aux2->Intern_Buffer); 
    #endif
} 

/* 
    Executa o comando de erro   
*/
void erro(int server_1,Server *S){  
    
    printf("ERRO %d\n",server_1);  
    Tpointer aux = find_node(server_1,S);
    show_buffer(aux->Intern_Buffer); 
    int tam = aux->Intern_Buffer.size;  
    Item *item = (Item*)malloc(sizeof(Item));  
    for(int i = 0; i < tam; i++){ 
         dequeue(&(aux->Intern_Buffer),item);
    }
} 

/* 
 Executa o comando send    
*/
void send(Server *S, int num){   
    #if DEBUG
        printf("SEND %d\n",num); 
    #endif 
    Tpointer Aux = S->nodeF->next;
    Item *item = (Item*)malloc(sizeof(Item)); 
    while (Aux != NULL){   
        if(Aux->Intern_Buffer.size > 0){
            dequeue(&(Aux->Intern_Buffer),item); 
            enqueue(&(S->History),item->data); 
        }
        Aux = Aux ->next;  
    }   
    #if DEBUG
        show(S->History);
    #endif
}  
/* 
Executa o comando de flush  
*/

void flush(Server *S){  
    if(S->History.size > 0)
        show_buffer(S->History); 
    Tpointer Aux = S->nodeF->next; 
    while (Aux != NULL) 
    {   
        show_buffer(Aux->Intern_Buffer);
        Aux = Aux ->next;  

    }  
    
    

} 

/* 
* Inicializa uma meganet (lista encadeada) 
* Cada c??lula da lista ?? um servidor 
* Cada servidor tem uma fila de mensagens
*/
void init_servers(Server *S,int num){ 
    init_server(S,num);  
}