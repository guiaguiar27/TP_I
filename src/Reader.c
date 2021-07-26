
#include "../include/Reader.h" 

void reader(char *FileName, Server *S) 
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
  if(file == NULL) {  
    printf("Error file\n"); 
    exit(1);
  }
  while(fgets(buff,MAX_CHAR_COMMAND,file)){  
    if(count_lines == 0){ 
      Servers = atoi(buff);  
      init_servers(S,Servers); 
    } 
    else{
      getsCommands(buff,S,Servers);
    }
    count_lines++;  
  } 
  fclose(file);
} 
 
/* 
Interpreta os comandos e convoca as funções equivalentes.    
*/
void getsCommands(char *buff, Server *ServerOP, int QtdServers){ 
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
    info(S, buff,ServerOP);
  }  
  if(strcmp(command,"WARN") ==0){ 
    S = atoi(strsep(&buff,tokenSpace));  
    I = atoi(strsep(&buff,tokenSpace)); 
    warn(S,I,ServerOP); 
  }  
  if(strcmp(command,"TRAN") == 0){ 
    S = atoi(strsep(&buff,tokenSpace));   
    S2 = atoi(strsep(&buff,tokenSpace)); 
    tran(S,S2,ServerOP);
  } 
  if(strcmp(command,"ERRO") == 0){ 
    S = atoi(strsep(&buff,tokenSpace));   
    erro(S,ServerOP);
  } 
  if((strcmp(command,"SEND\n") == 0) || (strcmp(command,"SEND") == 0)){  
    send(ServerOP,QtdServers);
  } 
  if((strcmp(command,"FLUSH\n") == 0) || (strcmp(command,"FLUSH") == 0)){  
    flush(ServerOP); 
  }  
  
}
