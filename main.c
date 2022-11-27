#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mylib/libmeter.h"
#include "Client.h"
#include "jsonParser.h"
#include "my_aes.h"




int main(int argc, char const *argv[])
{
	double total_consumption;
	double prev_consumption;
	int relay_status;

	char * encryptedJson;
	char *message;


    int ret = startMeterComm();
    printf("ret init %d \n",ret);
    if (ret == 0)
    {
    	total_consumption = getTotalConsumption();
    	prev_consumption = getPrevConsumption();
        relay_status = getRelayStatus();
        printf("Total : %.3f \n, Prev Day : %.3f \n,prevday_consumption,relay_status",total_consumption,prev_consumption,relay_status);

		char *json_string = GetJson(total_consumption,prev_consumption,relay_status);
        printf("\nJSON :%s\n",json_string);

        encryptedJson =encryptJson(json_string);
        int len = strlen(encryptedJson);

        message = (char *)malloc(len*(sizeof(char)));
        strncpy(message,encryptedJson,len);

        sendMessage(message);

    }
    else
    {
        printf("init fail : %d \n",ret);
    }

    return 0;
}
