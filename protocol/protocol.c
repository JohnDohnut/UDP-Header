#include "protocol.h"

protocol_packet_t* protocol_packet_init(){
	protocol_packet_t* packet = malloc(sizeof(protocol_packet_t));
	memset(packet,0,sizeof(protocol_packet_t));
}
void protocol_clear_msg(protocol_packet_t* packet){
	memset(packet->data,0,DATA_MAX_LENGTH);
	packet->header.data_len = 0;
	packet->header.data_type = -1;
	
}
void protocol_seq_id_increase(protocol_packet_t* packet){
	packet->header->seq_id ++;
}
void protocol_packet_destroy(protocol_packet_t* packet){
	free(packet);
}
int protocol_get_data_len(protocol_packet_s* packet){
	return packet->header.data_len;
}//getter of protocol_header.data_len
int protocol_set_message(protocol_packet_s* packet,char* data_buffer){
	if(memcmp(data_buffer,"/quit",sizeof("/quit")) == 0){
		memcpy(packet->data,data_buffer,DATA_MAX_LENGTH);
		return -2;
	}
	memcpy(packet->data,data_buffer,DATA_MAX_LENGTH);
	return memcmp(packet->data,data_buffer,DATA_MAX_LENGTH);1111
}










	
