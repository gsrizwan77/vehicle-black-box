/*
 * File:   Ext_EEPROM.c
 * Author: dilee
 *
 * Created on 10 December, 2025, 1:35 PM
 */

#include "main.h"
#include <xc.h>
    
void init_EEPROM(void)
{
	unsigned char dummy;

	/* Setting the CH bit of the RTC to Stop the Clock */
	dummy = read_EEPROM(SEC_ADDR);
	write_EEPROM(SEC_ADDR, dummy | 0x80); 

	/* Seting 12 Hr Format */
	dummy = read_EEPROM(HOUR_ADDR);
	write_EEPROM(HOUR_ADDR, dummy | 0x40); 

	/* 
	 * Control Register of DS1307
	 * Bit 7 - OUT
	 * Bit 6 - 0
	 * Bit 5 - OSF
	 * Bit 4 - SQWE
	 * Bit 3 - 0
	 * Bit 2 - 0
	 * Bit 1 - RS1
	 * Bit 0 - RS0
	 * 
	 * Seting RS0 and RS1 as 11 to achive SQW out at 32.768 KHz
	 */ 
	write_EEPROM(CNTL_ADDR, 0x93); 

	/* Clearing the CH bit of the RTC to Start the Clock */
	dummy = read_EEPROM(SEC_ADDR);
	write_EEPROM(SEC_ADDR, dummy & 0x7F); 

}

void write_EEPROM(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(ESLAVE_WRITE);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    for(int delay = 3000;delay--;);
}

unsigned char read_EEPROM(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(ESLAVE_WRITE);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(ESLAVE_READ);
	data = i2c_read();
	i2c_stop();

	return data;
}
