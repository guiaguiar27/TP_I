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
    //puts(buff);
    
    if(count_lines == 0){ 
    
      Servers = atoi(buff); 
      printf("Servers: %d\n",Servers);
    
    } 
    else{ 

    }  

    getsCommands(buff);
    count_lines++;  
  }  

  fclose(file);
} 

void getsCommands(char *buff){ 
  while(strcmp(buff,"\n")!= 0){ 
    printf("%c",*buff);
  }
}
