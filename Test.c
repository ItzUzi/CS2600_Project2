#include <stdio.h>
#include "DatesAndTime.h"

/**
 * Tester main function
*/
int main(int argc, char *argv[])
{
    int totalDays;
    totalDays = daysOnTrip();
    
    printf("\n\nThe total days on the trip are: %d", totalDays);
    
    return 0;
}
