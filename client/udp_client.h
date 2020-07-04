#ifndef __SERVER_H__
#define __SERVER_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "protocol.h"

#define SERVER_PORT 4000 // server port 
typedef struct udp_client_s udp_client_t;
struct udp_client_s{
	int SOCK;//SOCKET for client
	struct sockaddr_in* server_addr;//struct for server address
};
udp_client_t* udp_client_init();//initialize udp_client_t*
void udp_client_connect(udp_client_t* client);//send message to server and receieve response message from server.
void udp_client_destroy(udp_client_t* client);//release udp_client_t* client

#endif
