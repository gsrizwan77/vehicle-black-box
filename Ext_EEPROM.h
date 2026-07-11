/*
 * File:   Ext_EEPROM.h
 * Author: GS RIZWAN
 *
 * Created on 12 December, 2025, 8:00 PM
 */
#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h> 


#define ESLAVE_READ		0xA1
#define ESLAVE_WRITE		0xA0

#define SEC_ADDR		0x00
#define MIN_ADDR		0x01
#define HOUR_ADDR		0x02
#define DAY_ADDR		0x03
#define DATE_ADDR		0x04
#define MONTH_ADDR		0x05
#define YEAR_ADDR		0x06
#define CNTL_ADDR		0x07

void init_EEPROM(void);
void write_EEPROM(unsigned char address1,  unsigned char data);
unsigned char read_EEPROM(unsigned char address1);

#endif