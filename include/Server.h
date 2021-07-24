
#include "Buffer.h" 


typedef struct {
  Buffer Intern_Buffer;
  /* outros componentes */
} TItem;

typedef struct Tcell *Tpointer;

typedef struct Tcell {
  TItem Item;
  Tpointer next;
} Tcell;

typedef struct { 
  int Server_id;
  Tpointer node;
} Server;

/**  
 *   \brief Server implementation
 **/
void init_server(Server *S, int num);

void add_buffer(Server *S, Buffer new_buffer); 

Buffer *remove_buffer(Server *S);