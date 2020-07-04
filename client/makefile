
client : main.o udp_client.o data.o
	gcc -o client main.o udp_client.o data.o

main.o : main.c 
	gcc -c main.c

udp_client.o : udp_client.c
	gcc -c udp_client.c

data.o : data.c
	gcc -c data.c

clean:
	rm -rf *.o client

clean_obj:
	rm -rf *.o
	
remake:
	rm -rf *.o client
	make
