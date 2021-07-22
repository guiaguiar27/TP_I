 #include "Buffer.h" 

typedef struct Item{ 
    Buffer *Buffer;  
}Item;    

typedef struct cell{ 
    Item *item;  
    cell *next; 
}cell;   

typedef struct Server{ 
    cell *first, *last; 
    
}Server; 

