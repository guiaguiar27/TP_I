#include "../include/Reader.c" 
int main(int argc, char *argv[]){ 
    char *pre_name = (char*)malloc(sizeof(char));
    printf("file name:"); 
    scanf("%s",pre_name);
    //reader(*argv[1]); 
    reader(pre_name);
    return 0; 
}   