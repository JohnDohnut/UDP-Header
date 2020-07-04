#include "protocol.h"

protocol_packet_t* protocol_packet_init(){
	protocol_packet_t* packet = malloc(sizeof(protocol_packet_t));
	memset(packet,0,sizeof(protocol_packet_t));
}
void protocol_packet_destroy(protocol_packet_s* packet);
int protocol_get_data_len(protocol_packet_s* packet);//getter of protocol_header.data_len
int protocol_set_message(protocol_packet_s* packet,char* data_buffer);

	
