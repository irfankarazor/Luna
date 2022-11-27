/*
 * Manager.h
 *
 *  Created on: 26 Nov 2022
 *      Author: irfan.karazor
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



enum weekDays
{
    SUNDAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
};

char* monday	= "2.8.0";
char* tuesday	= "2.8.1";
char* wednesday	= "2.8.2";
char* thursday	= "2.8.3";
char* friday	= "2.8.4";
char* saturday	= "2.8.5";
char* sunday	= "2.8.6";




int startComm(void);
double getTotalConsumption(void);
double getPrevDayConsumption(void);
int getInternalRelayStatus(void);
double getValueFromArr(void);

#endif /* MANAGER_H_ */
