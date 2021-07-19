all:  
	gcc src/main.c src/Reader.c src/Controller.c src/Server.c -o main 
production: 
	gcc src/main.c  src/Reader.c src/Controller.c src/Server.c  -D POSITION=$(position) -o main 
clean:  
	rm main
