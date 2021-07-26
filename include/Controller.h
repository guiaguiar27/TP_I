#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  
#include "Server.h" 

/** 
* controller functions 
**/   

/**  
* Ao executar este comando, o conteúddo da variável ‘DADOS’ deve ser inserido no buffer do servidor ‘S’ 
**/ 
void info(int server, char *data,Server *S);  
/**  
* Um comando ‘WARN’  é executado pelo controlador central quando  é  detectada uma tentativa de hacking dos dados.
**/ 
void warn(int server, int position,Server *S); 
/**  
*  Este comando tem como finalidade desabilitar um servidor ‘S1’ quando são detectadas possíveis anomalias
**/ 
void tran(int server_1, int server_2,Server *S);
/**  
*  A execução de um comando de ERRO identifica que algo estranho ocorreu na mega- net.  
* Quando isso ocorre, deve-se imprimir no terminal a mensagem ‘ERRO <S>’ e todo o conteúdo do buffer do servidor ‘S’
**/ 
void erro(int server_1,Server *S); 
/**  
Quando o controlador central executa um comando ‘SEND’, 
deve-se percorrer os buffers de todos os servidores enviando os dados da primeira posição de cada um, e removendo-os do buffer.
**/ 
void send(Server *S,int num); 
/** 
 Ao executar um comando do tipo ‘FLUSH’, deve-se imprimir no terminal o histórico de consciências na ordem que foram enviadas. 
  Além disso, deve-se também imprimir no terminal,  
 o conteúdo do buffer de TODOS os servidores (a impressão de um buffer individual deve ser feita utilizando política FIFO).
**/ 
void flush(Server *S);  

void init_servers(Server *S, int num);