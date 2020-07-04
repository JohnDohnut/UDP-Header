#ifndef __DATA_H__
#define __DATA_H__
#include <stdio.h>
#include <stdlib.h>


#define BUFFER_SIZE 1024

typedef struct data_s data_t;

struct data_s{

	char DATA_BUFFER[BUFFER_SIZE];
};

data_t* data_init();
void data_destroy(data_t* data);
#endif
