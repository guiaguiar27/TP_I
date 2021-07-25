
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
      init_servers(S,Servers);
      
    
    } 
    else{
      getsCommands(buff);
    }

    count_lines++;  
  }  

  fclose(file);
} 

void getsCommands(char *buff, Server *ServerOP){ 
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
    #ifdef DEBBUG
      puts(buff); 
    #endif // DEBBUG
    info(S, buff,ServerOP);
  }  

  else if(strcmp(command,"WARN") ==0){ 
    S = atoi(strsep(&buff,tokenSpace));  
    I = atoi(strsep(&buff,tokenSpace)); 
    #if (DEBUG) 
      printf("S: %d, I: %d\n",S,I); 
    #endif 
    warn(S,I,ServerOP); 
  }  
  else if(strcmp(command,"TRAN") == 0){ 
    S = atoi(strsep(&buff,tokenSpace));   
    S2 = atoi(strsep(&buff,tokenSpace)); 
    #if (DEBUG) 
      printf("S: %d, S2: %d\n",S,S2); 
    #endif 
    tran(S,S2,ServerOP);
  } 
  else if(strcmp(command,"ERRO") == 0){ 
    S = atoi(strsep(&buff,tokenSpace));   
    #if (DEBUG) 
      printf("S: %d\n",S); 
    #endif 
    erro(S,ServerOP);
  } 
  else if(strcmp(command,"SEND") == 0){  
    #if (DEBUG) 
      printf("Send\n");
    #endif  
    send(ServerOP);;

  } 
  else if(strcmp(command,"FLUSH") == 0){ 
    #if (DEBUG) 
      printf("Flush\n"); 
    #endif 
    flush(ServerOP); 
  }  
  
}
