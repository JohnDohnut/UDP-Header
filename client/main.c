#include "udp_client.h"

int main(int argc, char* argv[]){
	printf("openning udp client. Hail our lord James Jeong\n");
	udp_client_t* client = udp_client_init();
	udp_client_connect(client);
	udp_client_destroy(client);
	return 0;
	
}
