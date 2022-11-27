#include "Manager.h"

#include "mylib/libmeter.h"

#define  RELAYSTATUS "1.9.0"
#define READTOTALCONSUMTION  "readout"
char* prev_day_consumption;
char get_buff[100];


int startMeterComm(void){
    return initializeMeterComm();
}

double getTotalConsumption(void){
    int ret = getValueFromMeter(get_buff, READTOTALCONSUMTION);
    printf("%s\n",get_buff);
	return getValueFromArr();
}

double getPrevConsumption(void){

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("weekday: %d\n", tm.tm_wday);
    switch (tm.tm_wday)
    {
		case SUNDAY:
			prev_day_consumption = saturday;
		  break;
		case MONDAY:
			prev_day_consumption = sunday;
		  break;
		case TUESDAY:
			prev_day_consumption = monday;
		  break;
		case WEDNESDAY:
			prev_day_consumption = tuesday;
		  break;
		case THURSDAY:
			prev_day_consumption = wednesday;
		  break;
		case FRIDAY:
			prev_day_consumption = thursday;
		  break;
		case SATURDAY:
			prev_day_consumption = friday;
		  break;
		default:
			prev_day_consumption = NULL;
    }

    if (prev_day_consumption != NULL)
    {
        int ret = getValueFromMeter(get_buff, prev_day_consumption);
        printf("%s\n",get_buff);
        return getValueFromArr();
    }else
    {
        printf("Time ERROR : Day of week does not detected.");
        return 0.000;
    }

}

double getValueFromArr(void)
{
    int start_index = 0;
    int end_index = 0;
    char* float_value;

    for (int i = 0; i < strlen(get_buff); i++)
    {
        if (get_buff[i] == '(')
        {
            start_index = i+1;
        }
        else if (get_buff[i] == ')')
        {
            end_index = i;
            get_buff[i] = '\0';
            break;
        }
    }
    strncpy(float_value,&get_buff[start_index],(end_index-start_index)+1);
    char temp[strlen(float_value)];
    strcpy(temp,float_value);

    double converted_value= atof(temp);
    //printf(" float : %.3f\n",d);
    return converted_value;
}

int getRelayStatus(void){
    int ret = getValueFromMeter(get_buff, RELAYSTATUS);
    int index = strlen(get_buff);
    char bool_value[1];
    bool_value[0] = get_buff[index-1];

    int converted_value = atoi(bool_value);

    printf("%s -- val : %d\n",get_buff,converted_value);

    return converted_value;
}
