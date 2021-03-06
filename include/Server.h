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
  Buffer History; 
} Server;



/**  
 *   \brief Server implementation
 **/
void init_server(Server *S, int num);

void add_buffer(Server *S, int id);

Tpointer find_node(int id, Server *S); 


void to_send(Server *S, Buffer *history);