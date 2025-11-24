/*
 * ringbuffer.h
 *
 *  Created on: Sep 3, 2025
 *      Author: Precision
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_
#include"stdint.h"
#include "stddef.h"

typedef struct {
    uint8_t *pt;
    uint32_t head;
    uint32_t tail;
    uint32_t size;
} RINGBUF;

int32_t RINGBUF_Init(RINGBUF* r ,uint8_t* buf , uint32_t size);
int32_t RINGBUF_Put(RINGBUF* r , uint8_t c);
int32_t RINGBUF_Get(RINGBUF* r , uint8_t* c);
int32_t RINGBUF_Clear(RINGBUF* r, uint8_t num);
uint32_t RINGBUF_Available(RINGBUF *r);
void RINGBUF_GetArray(RINGBUF *r, uint8_t *data, uint32_t len);



#endif /* INC_RINGBUFFER_H_ */
