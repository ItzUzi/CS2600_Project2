#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Method checks how long the trip was as well
 * how long stay is
 * Time related variables will be taken in 24 hr
 * format
 * 
 * Returns costs of airfare
 */
double airPlane(){
    double timeOfArrival;


    return 0;
}

/**
 * Asks user for amount of days they
 * have stayed in trip
 * Returns amount of days as type int
*/
int daysOnTrip(){
    char input;
    int days = 0;
    printf("\nPlease input amount of days this trip will take.\n");
    scanf("%s",&input);
    
    days = atoi(&input);

    if (days > 0 && atoi(&input))
        return days;
    else{
        printf("\nSelect only numbers greater than 0\n");
        return daysOnTrip();
    }
    
}

/**
 * Asks user for time of arrival on first day
 * returns that value as a double in order to calculate other costs
*/
double getArrivalTime(){
    char input;
    double arrivalTime;

    printf("\nPlease input the time of arrival. (0-23)\n");
    printf("(6.25 = 6:15am, 18.5 = 6:30pm)\n");
    scanf("%s", &input);

    arrivalTime = strtod(&input, NULL);

    if(arrivalTime > -1 && arrivalTime <= 23 && strtod(&input, NULL))
        return arrivalTime;
    else{
        printf("Please select an acceptable time");
        return timeOfArrival();
    }
}