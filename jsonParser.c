#include "jsonParser.h"
#include "cJSON.h"
#include "cJSON_Utils.h"


cJSON *root = NULL;





char* GetJson(double total,double prev_day,int relay_stat)
{
	if(root != NULL)
	{
		cJSON_Delete(root);
	}
    root = cJSON_CreateObject();
   
    addTime();
    addConsumptions(total,prev_day);
    addRelayStatus(relay_stat);

    char *returnJsonDataCopy = NULL;
    char *mergedJsonData =  cJSON_PrintUnformatted(root);

    int length = strlen(mergedJsonData);
    returnJsonDataCopy = (char *)malloc(length + 1);

    memcpy(returnJsonDataCopy, mergedJsonData, length + 1);

    cJSON_free(mergedJsonData);
    cJSON_Delete(root);

   return returnJsonDataCopy;

}

void addTime(void)
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;
    cJSON *date = NULL;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d.%m.%Y %H:%M:%S", tm_info);
    date = cJSON_CreateString(buffer);

    cJSON_AddItemToObject(root, "date", date);

}
void addConsumptions(double totalCons,double prevDayCons){
    
	cJSON *consumptions = cJSON_CreateObject();
	cJSON_AddItemToObject(root, "consumption", consumptions);
	cJSON_AddNumberToObject(consumptions, "total", totalCons);
	cJSON_AddNumberToObject(consumptions, "previous_day", prevDayCons);
}

void addRelayStatus(int relayStat)
{

	cJSON_AddBoolToObject(root,"relay_status",(relayStat != 0));
}
