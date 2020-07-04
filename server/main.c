#include "udp_server.h"

int main(int argc, char* argv[]){
	printf("openning udp server. Hail our lord James Jeong\n");
	udp_server_t* server = udp_server_init();
	udp_server_connect(server);
	udp_server_destroy(server);
	return 0;
	
}
