/*
 * Parse_data_UART.c
 *
 *  Created on: Oct 8, 2025
 *      Author: Precision
 */
#include "Parse_data_UART.h"


uint8_t pos_vel_1[15];
uint8_t pos_vel_2[15];
uint8_t pos_vel_3[15];
uint8_t pos_vel_4[15];
uint8_t pos_vel_5[15];
uint8_t pos_vel_6[15];
uint8_t pos_vel_7[15];

void parse_joint(uint8_t *data, uint8_t len){
    uint16_t start = 0;
    uint8_t index_of_joint = 0;

    for (uint16_t i = 0; i <= len; i++)
    {
        if (data[i] == '|' || data[i] == '\0' || i == len)
        {
            uint16_t cnt = i - start;
            if (cnt > 0)
            {
                if (cnt >= 15)
                    cnt = 14;

                switch (index_of_joint)
                {
                case 0:
                    memcpy(pos_vel_1, &data[start], cnt);
                    pos_vel_1[cnt] = '\0';
                    break;
                case 1:
                    memcpy(pos_vel_2, &data[start], cnt);
                    pos_vel_2[cnt] = '\0';
                    break;
                case 2:
                    memcpy(pos_vel_3, &data[start], cnt);
                    pos_vel_3[cnt] = '\0';
                    break;
                case 3:
                    memcpy(pos_vel_4, &data[start], cnt);
                    pos_vel_4[cnt] = '\0';
                    break;
                case 4:
                    memcpy(pos_vel_5, &data[start], cnt);
                    pos_vel_5[cnt] = '\0';
                    break;
                case 5:
                	memcpy(pos_vel_6, &data[start], cnt);
                	pos_vel_6[cnt] = '\0';
                	break;
                case 6:
                	memcpy(pos_vel_7, &data[start], cnt);
                	pos_vel_7[cnt] = '\0';
                	break;
                default:
                    break;
                }

                index_of_joint++;
            }
            start = i + 1;
        }
    }
}
void parse_buffer_to_struct(uint8_t *data, joint_in4 *out)
{
    char *token;
    char buffer[15];

    strncpy(buffer, (char*)data, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    token = strtok(buffer, ";");
    if (token != NULL)
        out->pos = atof(token);

    token = strtok(NULL, ";");
    if (token != NULL)
        out->vel = atof(token);
}



