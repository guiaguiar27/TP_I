all:  
	gcc src/main.c src/Reader.c src/Controller.c src/Server.c src/Buffer.c -o main 
production: 
	gcc src/main.c  src/Reader.c src/Controller.c src/Server.c src/Buffer.c -D POSITION=$(position) -o main 
clean:  
	rm main
