#include "../include/Server.h" 

/* 
    Inicia um servidor 
*/
void init_server(Server *S, int num){ 
    S->nodeF = (Tpointer)malloc(sizeof(Tcell));
    S->nodeL = S->nodeF;
    S->nodeF->next = NULL;  
    
    for(int i =0; i < num; i++){ 
        add_buffer(S,i);
        
    } 
    empity_buffer(&S->History,0); 
}

/* 
Adiciona um novo buffer ao servidor N 
Cada buffer pode ter n celulas  
*/
void add_buffer(Server *S, int id){ 
    S->nodeL->next = (Tpointer) malloc(sizeof(Tcell));
    S->nodeL = S->nodeL->next; 
    empity_buffer(&S->nodeL->Intern_Buffer,id);
    S->nodeL->next = NULL;
} 

/* 
Encontra um nó especifico do servidor de acordo com seu id 
*/
Tpointer find_node(int id, Server *S){ 
    Tpointer Aux;
    Aux = S->nodeF-> next;
    while (Aux != NULL) 
    {   
        if(Aux->Intern_Buffer.id == id) 
            return Aux;
        Aux = Aux -> next;
    } 
    return NULL;
}



