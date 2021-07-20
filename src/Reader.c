#include "../include/Controller.h" 
#include "../include/Reader.h" 

void reader(char *FileName) 
{ 
  int count_lines;   
  int Servers;   
  
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
    
    if(count_lines == 0){ 
    
      Servers = atoi(buff); 
      printf("Servers: %d\n",Servers);
    
    } 
    if(count_lines == 1){ 
        getsCommands(buff);
    }  

    count_lines++;  
  }  

  fclose(file);
} 

void getsCommands(char *buff){   
  char tokenSpace =  " "; 
  char tokenQuote =  "\"";
  char *slot = malloc(sizeof(char)); 
  slot = strtok(buff,tokenSpace); 
  while(slot != NULL){  
    
    slot = strtok(NULL,tokenSpace);
  }
}
