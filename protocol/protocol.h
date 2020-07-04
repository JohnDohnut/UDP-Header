/**
*client includes client.h, protocol.h
*server includes server.h, protocol.h
*definition of data packet is dettached from server.h, client.h
*Header and Data buffer is seperated in packet.
*/

#pragma once
#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <memory.h>

#define DATA_MAX_LEN 1024

typedef struct protocol_header_s protocol_header_t;
struct protocol_header_s{
	uint32_t seq_id
	int data_type;
	int data_len;
};

typedef struct protocol_packet_s protocol_packet_t;
struct protocol_packet_s{
	protocol_header_t header;
	char data[DATA_MAX_LEN];
};

protocol_packet_s* protocol_packet_init();
void protocol_packet_destroy(protocol_packet_s* packet);
int protocol_get_data_len(protocol_packet_s* packet);//getter of protocol_header.data_len
int protocol_set_message(protocol_packet_s* packet,char* data_buffer);

#endif





