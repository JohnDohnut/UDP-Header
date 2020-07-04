
server : main.o udp_server.o data.o
	gcc -o server main.o udp_server.o data.o

main.o : main.c 
	gcc -c main.c

udp_server.o : udp_server.c
	gcc -c udp_server.c

data.o : data.c
	gcc -c data.c

clean:
	rm -rf *.o server

clean_obj:
	rm -rf *.o
	
remake:
	rm -rf *.o server
	make
