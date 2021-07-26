#include "../include/Controller.h"  



void info(int server, char *data,Server *S){   
    printf("INFO\n");
    Tpointer aux = find_node(server,S);
    
    printf("Buffer id:%d\n",aux->Intern_Buffer.id); 
    enqueue(&(aux->Intern_Buffer),data);   
    show(aux->Intern_Buffer);

} 
void warn(int server, int position, Server *S){  
    puts("WARN");
    //Tpointer *aux = find_node(server,S);   
    //show_servers(&S);
    //move_to_front(&((*aux)->Item.Intern_Buffer),position);

} 

void tran(int server_1, int server_2,Server *S){ 

}
void erro(int server_1,Server *S){  
    printf("ERRO %d\n",server_1);  
    Tpointer aux = find_node(server_1,S);
    show(aux->Intern_Buffer); 
    int tam = aux->Intern_Buffer.size;  
    Item *item; 
    // for(int i = 0; i < tam; i++){ 
    //     dequeue(S,item);
    // }
    // show(&(aux->Intern_Buffer));
} 

/* 
 Executa o comando flush    
*/
void send(Server *S, int num){   
    printf("SEND %d\n",num);
    char *history = (char*)malloc(num*sizeof(char)); 
    pick_to_send(S,history);

} 

void flush(Server *S){ 

} 

/* 
* Inicializa uma meganet (lista encadeada) 
* Cada célula da lista é um servidor 
* Cada servidor tem uma fila de mensagens
*/
void init_servers(Server *S,int num){ 
    puts("Init Servers");
    init_server(S,num); 
    
}