#include "../include/Server.h" 


void init_server(Server *S, int num){ 
    for(int i = 0; i < num; i++){ 
        S->node = (Tpointer)malloc(sizeof(Tcell)); 
        S->Server_id = i;  
        S->node->next = NULL;  
    }

}

void add_buffer(Server *S, Buffer new_buffer){ 
    S->node->Item.Intern_Buffer = new_buffer; 
    S->node->next = NULL;     

}

Buffer *remove_buffer(Server *S);