#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Asks user for amount of days they
 * have stayed in trip
 * Returns amount of days as type int
*/
int daysOnTrip(){
    char input;
    int days = 0;
    printf("\nPlease input amount of days this trip will take: ");
    scanf("%s",&input);
    
    days = atoi(&input);

    if (days > 0 && atoi(&input))
        return days;
    else{
        printf("\nInput only numbers greater than 0\n");
        return daysOnTrip();
    }
    
}

/**
 * Asks user for time of arrival/departure
 * returns that value as a double in order to calculate other costs
 * time is in 24hr format
*/
double setTime(char *status){
    char input;
    double time, minutes;

    printf("\nPlease input the time of %s. (1-24)\n", status);
    printf("(6.25 = 6:25am, 18.3 = 6:30pm)\n");
    scanf("%s", &input);

    time = strtod(&input, NULL);
    // Gets minute value by only looking at everything after the decimal place
    minutes = time - trunc(time);

    //Checks if minutes is larger than 60
    if(minutes > .59){
        printf("invalid time.");
        return setTime(status);
    }

    if(time >= 1 && time < 25){
        if (time == 24)
            time = 0;
        return time;
    }
    else{
        printf("Please select an acceptable time");
        return setTime(status);
    }
}