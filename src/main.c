#include "../include/Reader.h"  

int main(int argc, char *argv[]){ 
    
    Server *S = (Server*)malloc(sizeof(Server));   
    reader(argv[1],S);
    return 0; 
}   