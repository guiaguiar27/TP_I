#include "../include/Reader.h"  

int main(int argc, char *argv[]){ 
    
    //reader(*argv[1]);  
    Server *S = (Server*)malloc(sizeof(Server));  
    //printf("Rodando!\n");
    reader("teste.txt",S);
    return 0; 
}   