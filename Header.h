﻿/*
 * Header.h
 *
 * Created: 13.12.2022 16:36:24
 *  Author: Samuel Lüthi
 */ 


#ifndef HEADER_H_
#define HEADER_H_
/*** Project includes ***/
#include <avr/io.h>
#include "avr-lcd-lib.h"
#include "avr-twi-lib.h"

#define VAL_RESET		0xB6

#define VAL_MODE_SLEEP	0b00
#define VAL_MODE_FORCED	0b01

#define VAL_OSRS_SKIP	0b000
#define VAL_OSRS_1		0b001
#define VAL_OSRS_2		0b010
#define VAL_OSRS_4		0b011
#define VAL_OSRS_8		0b100
#define VAL_OSRS_16		0b101

#define VAL_FILTER_0	0b000
#define VAL_FILTER_1	0b001
#define VAL_FILTER_3	0b010
#define VAL_FILTER_7	0b011
#define VAL_FILTER_15	0b100
#define VAL_FILTER_31	0b101
#define VAL_FILTER_63	0b110
#define VAL_FILTER_127	0b111

#define VAL_HEATPROF_0	0
#define VAL_HEATPROF_1	1
#define VAL_HEATPROF_2	2
#define VAL_HEATPROF_3	3
#define VAL_HEATPROF_4	4
#define VAL_HEATPROF_5	5
#define VAL_HEATPROF_6	6
#define VAL_HEATPROF_7	7
#define VAL_HEATPROF_8	8
#define VAL_HEATPROF_9	9

#define VAL_HEAT_ON		0b0
#define VAL_HEAT_OFF	0b1

#define VAL_RUN_GAS_ON	0b1
#define VAL_RUN_GAS_OFF	0b0

#define VAL_DEL_MULT_1	0b00
#define VAL_DEL_MULT_4	0b01
#define VAL_DEL_MULT_16	0b10
#define VAL_DEL_MULT_64	0b11

/*** CONTROL REGISTERS BME680 ***/
#define REG_CTR_HUM		0x72		//
#define REG_CONFIG		0x75		//	FILTER<4:2> ( FILTER )
#define REG_CTRL_MEAS	0x74		//	MODE<1:0> ( MODE ) , OSRS_T<7:5> ( TEMPERATURE OVERSAMPLING ) , OSRS_P<4:2>	( PRESSURE OVERSAMPLING )
#define REG_STATUS		0x73		//
#define REG_RESET		0xE0		//	RESET<7:0> ( SOFT_RESET )
#define REG_ID			0xD0		//	CHIP_ID<7:0> ( CHIP_ID OF THE DEVICE )
#define REG_CTRL_HUM	0x72		//	OSRS_H<2:0> ( HUMIDITY OVERSAMPLING )

#define REG_IADC_HEAT_0	0x50		//
#define REG_IADC_HEAT_1	0x51		//
#define REG_IADC_HEAT_2	0x52		//
#define REG_IADC_HEAT_3	0x53		//
#define REG_IADC_HEAT_4	0x54		//
#define REG_IADC_HEAT_5	0x55		//
#define REG_IADC_HEAT_6	0x56		//
#define REG_IADC_HEAT_7	0x57		//
#define REG_IADC_HEAT_8	0x58		//
#define REG_IADC_HEAT_9	0x59		//

#define REG_RES_WAIT_0	0x5A		//
#define REG_RES_WAIT_1	0x5B		//
#define REG_RES_WAIT_2	0x5C		//
#define REG_RES_WAIT_3	0x5D		//
#define REG_RES_WAIT_4	0x5E		//
#define REG_RES_WAIT_5	0x5F		//
#define REG_RES_WAIT_6	0x60		//
#define REG_RES_WAIT_7	0x61		//
#define REG_RES_WAIT_8	0x62		//
#define REG_RES_WAIT_9	0x63		//

#define REG_GAS_WAIT_0	0x64		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x65		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x66		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x67		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x68		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x69		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x6A		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x6B		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x6C		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )
#define REG_GAS_WAIT_0	0x6D		//	GAS_WAIT<5:0> ( DELAY BETWEEN HEAT AND MEASUREMENT IN ms ) , GAS_MULTIPLYER<7:6> ( GAS DELAY MULTIPLYER )

#define REG_CTRL_GAS_0	0x70		//	HEAT_OFF<3> ( HEAT ON/OFF )
#define REG_CTRL_GAS_1	0x71		//	NB_CANV<3:0> ( SELECT HEATER SET POINT ) , RUN_GAS<4> ( RUN GAS MEASURMENT )

/*** DATA REGISTERS BME680 ***/
#define REG_PRESS_MSB	0x1F
#define REG_PRESS_LSB	0x20
#define REG_PRESS_XLSB	0x21

#define REG_TEMP_MSB	0x22
#define REG_TEMP_LSB	0x23
#define REG_TEMP_XLSB	0x24

#define REG_HUM_MSB		0x25
#define REG_HUM_MSB		0x26

#define REG_GAS_R_MSB	0x2A
#define	REG_GAS_R_LSB	0x2B




#endif /* HEADER_H_ */