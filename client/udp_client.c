#include "udp_client.h"


/**
*@brief initialize and return udp_client_t*
*@return udp_client_t*
*@detail
*initializing process includes socket().
*using port 4000.
*if fail to socket(), then exit program.
*/
udp_client_t* udp_client_init(){
	printf("client socket init...\n");
	udp_client_t* client = malloc(sizeof(udp_client_t));
	client->data = data_init();
	client->server_addr = malloc(sizeof(struct sockaddr_in));
	memset(client->server_addr,0,sizeof(struct sockaddr_in));
	client->server_addr->sin_family = AF_INET;
	inet_aton("127.0.0.1", (struct in_addr*) &client->server_addr->sin_addr.s_addr);
	client->server_addr->sin_port = htons(SERVER_PORT);

	if((client->SOCK = socket(AF_INET,SOCK_DGRAM,0))==-1){
		printf("socket() failed\n");
		exit(1);
	}
	printf("client socket init done...\n");
	return client;
}
/**
*@brief send message to server and recieve response message from server.
*@param udp_client_t*
*@detail
*We can define various response message based on protocol which users(of both server and client).
*In this case, server simply sends "ACK\n" if server recieved message.
*However, Since we don't know actual recieve byte of server, it's vulnerable to partially damaged message.
*But since I hate numbers, I simply get "ACK\n". 
*Also, to get exact length of string which were sent, strlen() will be more precise than using sendbytes.
*/
void udp_client_connect(udp_client_t* client){
	ssize_t sendbytes;
	ssize_t recvbytes;
	int addr_len=sizeof(struct sockaddr);
	int i=0;
	protocol_packet_t* send_packet = protocol_packet_init();
	protocol_packet_t* recv_packet = protocol_packet_init();
	char user_buffer[DATA_MAX_LENGTH];
	while(1){
		printf("wating for input...\n");
		fgets(user_buffer, DATA_MAX_LENGTH-1,stdin);
		for(i=0;i<DATA_MAX_LENGTH;i++){
			if(user_buffer[i] == '\n')
					user_buffer[i] = '\0';
		}
		data_buffer[DATA_MAX_LENGTH-1] = '\0';
		protocol_set_message(send_packet,user_buffer);
		sendbytes = sendto(client->SOCK,send_packet,sizeof(protocol_packet_t),0,(struct sockaddr*)client->server_addr,sizeof(struct sockaddr));
		if(sendbytes == -1){
			printf("send msg failed.\n1 : continue\n2 : terminate client\n");
			//send error handling
			
		}
		printf("msg : %s, send bytes : %d\n",client->data->DATA_BUFFER,sendbytes);
		recvbytes = recvfrom(client->SOCK,recv_packet,sizeof(protocol_packet_t),0,(struct sockaddr*)(client->server_addr),&addr_lepacket_n);
		if(recvbytes<=0){
			printf("not ACKed\n");
		}
		else{
			printf("response from server:%s\n",recv_packet->data);
		}
	}
}
/**
*@breif release udp_client_t* client
*@param udp_client_t*
*@detail 
*Since there's no way to terminante the program without using SIGINT, this function will never be called.
*So handler for SIGINT or user defined command is needed to terminate program stably. 
*/
void udp_client_destroy(udp_client_t* client){
	close(client->SOCK);
	free(client);
	
}

int main(int argc, char* argv[]){
	printf("openning udp client. Hail our lord James Jeong\n");
	udp_client_t* client = udp_client_init();
	udp_client_connect(client);
	udp_client_destroy(client);
	return 0;
	
}
