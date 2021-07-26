#include "Buffer.h"

typedef struct Tcell *Tpointer;

typedef int TipoChave;



typedef struct Tcell{
  Buffer Intern_Buffer;
  Tpointer next;
} Tcell;

typedef struct Server{
  Tpointer nodeF, nodeL; 
  int Server_id;
} Server;



/**  
 *   \brief Server implementation
 **/
void init_server(Server *S, int num);

void add_buffer(Server *S, Buffer *new_buffer, int id);

//Buffer *remove_buffer(Server **S); 
Tpointer find_node(int id, Server *S); 

void show_servers(Server *S);

void pick_to_send(Server *S, char *history);