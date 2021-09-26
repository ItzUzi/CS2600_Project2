#include <stdio.h>
#include "DatesAndTime.h"

/**
 * Tester main function
*/
int main(int argc, char *argv[])
{
    double timeOfArrival;
    timeOfArrival = getArrivalTime();
    char dayTime[3];

    if (timeOfArrival < 12)
        strcpy(dayTime,"am");
    else
        strcpy(dayTime, "pm");
    
    
    printf("\n\narrived to destination at: %.2lf%s", timeOfArrival, dayTime);
    
    return 0;
}
