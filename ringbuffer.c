/*
 * ringbuffer.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Precision
 */

#include "ringbuffer.h"

int32_t RINGBUF_Init(RINGBUF* r ,uint8_t* buf , uint32_t size){
	if(r ==NULL || buf == NULL || size < 2) return -1;

	r->pt = buf;
	r->head = 0;
	r->tail = 0;
	r->size = size;

	return 0;
}

int32_t RINGBUF_Put(RINGBUF* r , uint8_t c){
	uint32_t temp ;
	temp = r->head;
	temp++ ;
	if(temp >= r->size){
		temp = 0;
	}
	if(temp == r->tail){
		return -1;
	}

	r->pt[r->head] = c;
	r->head = temp;

	return 0;
}

int32_t RINGBUF_Get(RINGBUF* r , uint8_t* c){
	if(r->tail == r->head){
		return -1;
	}
		*c= r->pt[r->tail];
		r->tail++;
	if(r->tail >= r->size){
		r->tail = 0;
	}
	return 0;

}

int32_t RINGBUF_Clear(RINGBUF* r, uint8_t num){
	if(r->tail == r->head){
		return -1;
	}
	if(num > r->head - r->tail){
		num= r->head - r->tail;
	}

	r->head = r->head - num;
	return 0;
}

uint32_t RINGBUF_Available(RINGBUF *r)
{
    if (r->head >= r->tail)
        return (r->head - r->tail);
    else
        return (r->size - (r->tail - r->head));
}


void RINGBUF_GetArray(RINGBUF *r, uint8_t *data, uint32_t len)
{
    for (uint32_t i = 0; i < len; i++)
    {
        // Nếu buffer rỗng thì dừng
        if (r->head == r->tail)
            break;

        data[i] = r->pt[r->tail];
        r->tail = (r->tail + 1) % r->size;
    }
}





