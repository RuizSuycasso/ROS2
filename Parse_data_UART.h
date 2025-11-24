/*
 * Parse_data_UART.h
 *
 *  Created on: Oct 8, 2025
 *      Author: Precision
 */

#ifndef INC_PARSE_DATA_UART_H_
#define INC_PARSE_DATA_UART_H_

#include "stdint.h"
#include "string.h"
#include "stdlib.h"

typedef struct{
	float pos;
	float vel;
}joint_in4;


typedef enum{
	parse_Free,
	parse_UART_ok,
	parse_to_buffer_ok,
	parse_to_struct_ok,
	parse_error
}status_of_parse_buffer;

extern uint8_t pos_vel_1[15];
extern uint8_t pos_vel_2[15];
extern uint8_t pos_vel_3[15];
extern uint8_t pos_vel_4[15];
extern uint8_t pos_vel_5[15];
extern uint8_t pos_vel_6[15];
extern uint8_t pos_vel_7[15];



void parse_joint(uint8_t *data, uint8_t len);
void parse_buffer_to_struct(uint8_t *data, joint_in4 *out);



#endif /* INC_PARSE_DATA_UART_H_ */
