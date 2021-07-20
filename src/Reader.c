#include "../include/Controller.h" 
#include "../include/Reader.h" 

void reader(char *FileName) 
{ 
  int count_lines;  
  char pre_path[] =  "./src/"; 
  char *path = malloc(strlen(pre_path) + strlen(FileName) + 1);   
  strcat(path,pre_path); 
  strcat(path,FileName); 
  
  FILE *file = NULL;    
  file = fopen(path,"r");  

  char *buff = (char*)malloc(sizeof(char)); 
  
  if(file == NULL) 
  {  
    printf("Error file\n"); 
    exit(1);
  }
  
  while(fgets(buff,MAX_CHAR_COMMAND,file)) 
  {  
    printf("%s\n",buff); 
    
    if(count_lines == 0){ 
      // how much servers 
    }  

    count_lines++;  
  } 
  fclose(file);
}