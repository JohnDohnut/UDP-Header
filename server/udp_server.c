#include "udp_server.h"
/**
*@brief initialize and return udp_server_t*
*@return udp_server_t*
*@detail
*initializing process includes socket() and bind()
*using port 4000.
*if fail to socket() or bind(), exit program.
*/
udp_server_t* udp_server_init(){
	udp_server_t* server = malloc(sizeof(udp_server_t));	
	server->data = data_init();
	server->server_addr = malloc(sizeof(struct sockaddr_in));
	memset(server->server_addr,0,sizeof(struct sockaddr_in));
	server->server_addr->sin_family = AF_INET;
	server->server_addr->sin_port = htons(SERVER_PORT);
	server->server_addr->sin_addr.s_addr=htonl(INADDR_ANY);
	server->SOCK = socket(PF_INET,SOCK_DGRAM,0);
	if(server->SOCK <0){
		printf("socket() failed\n");
		free(server);
		exit(0);	
	}
	if(bind(server->SOCK, (struct sockaddr*)server->server_addr, sizeof(struct sockaddr))<0){
		printf("bind() faild\n");
		close(server->SOCK);
		free(server);
		exit(1);
	}
	
	return server;
}
/**
*@brief server listen
*@param udp_server_t*
*@detail
*recieve data from client using recvfrom and send "ACK\n" if recv_bytes>0. 
*If recv_bytes<0, then exit().
*Since SIGINT is only way to terminate the program, for now, we need to add handler for SIGINT, which escape this function so udp_server_destroy can be called.
*By adding some conditions, it's possible to vary the response message of server. 
*But it will cost resource.
*/
void udp_server_connect(udp_server_t* server){
	int i;
	printf("connecting...\n");
	printf("SOCK no : %d\n",server->SOCK);
	printf("%s\n",server->data->DATA_BUFFER);
	if(server->SOCK <=0){
		free(server);
		printf("socket fd error while connection\n");
		exit(1);
	}
	struct sockaddr_in client_addr;
	int addr_len = sizeof(struct sockaddr);
	ssize_t recv_bytes;
	memset(&client_addr,0,addr_len);
	printf("client addr struct init done...\n");
	while(1){
		printf("waiting for msg\n");
		recv_bytes = recvfrom(server->SOCK, server->data->DATA_BUFFER,BUFFER_SIZE,0,(struct sockaddr*)(&client_addr),&addr_len);
		if(recv_bytes<=0){
			printf("%d\n",recv_bytes);
			printf("failed to recv data from client\n");
			exit(1);
		}
		else{	
			server->data->DATA_BUFFER[server->data->SIZE_OF_DATA-1] = '\0';
			printf("Message from client : %s\n",server->data->DATA_BUFFER);
			sendto(server->SOCK,"ACK\n",4, 0, (struct sockaddr*)(&client_addr), sizeof(client_addr));
		}

		
	}
		
}

/**
*@brief release udp_server_t*
*@param udp_server_t*
*/
void udp_server_destroy(udp_server_t* server){
	printf("Shutdown server...");
	close(server->SOCK);		
	free(server);
}

