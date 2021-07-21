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
  int S, S2, I,aux; 
  short flag = 0;  

  char *tokenSpace =  " "; 
  char *tokenQuote =  "\"";
  char *slot = malloc(sizeof(char)); 
  char *data = malloc(sizeof(char)); 
  char *command = malloc(sizeof(char)); 


  slot = strsep(&buff,tokenSpace);  
  strcpy(command,slot);
  if(strcmp(command,"INFO") ==0){  
    S = atoi(strsep(&buff,tokenSpace));  
    puts(buff); 
    info(S, buff);
  }  
  
  else if(strcmp(command,"WARN") ==0){ 

  }  
  else if(strcmp(command,"TRAN") == 0){ 

  } 
  else if(strcmp(command,"ERRO") == 0){ 

  } 
  else if(strcmp(command,"SEND") == 0){ 

  } 
  else if(strcmp(command,"FLUSH") == 0){ 

  }  
  else if(strcmp(command,"INFO") == 0){ 

  } 
  while(slot != NULL){  
    slot = strtok(NULL,tokenSpace); 
    
  }
}
