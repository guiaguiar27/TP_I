#include "../include/Server.h" 

void init_server(Server *S, int num){ 
    S->nodeF = (Tpointer)malloc(sizeof(Tcell));
    S->nodeL = S->nodeF;
    S->nodeF->next = NULL;  
    
    for(int i =0; i < num; i++){ 
        Buffer buffer; 
        empity_buffer(&buffer,i);
        add_buffer(S,&buffer,i);
        
    }
}


void add_buffer(Server *S, Buffer *new_buffer, int id){ 
    S->nodeL->next = (Tpointer) malloc(sizeof(Tcell));
    S->nodeL = S->nodeL->next; 
    S->nodeL->Intern_Buffer = *new_buffer;
    S->nodeL->next = NULL;
}

//Buffer *remove_buffer(Server **S); 
Tpointer find_node(int id, Server *S){ 
    Tpointer Aux;
    Aux = S->nodeF-> next;
    while (Aux != NULL) 
    {   
        if(Aux->Intern_Buffer.id == id) 
            return Aux;
        //printf("ID: %d\n",Aux->Intern_Buffer.id);
        Aux = Aux -> next;
    }
}

void show_servers(Server *S);

void pick_to_send(Server *S, char *history){ 
    Tpointer Aux;
    Aux = S->nodeF-> next; 
    Item *i; 
    while (Aux != NULL) 
    {   
        dequeue(&(Aux->Intern_Buffer), i); 
        //strcpy(history,i->data); 
        printf("%s\n",i->data);
        Aux = Aux -> next; 
        //history++;
    } 

}

