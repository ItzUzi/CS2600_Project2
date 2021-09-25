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
 * Only being used as a tester so far
*/
int main(int argc, char *argv[]){
    
    daysOnTrip();

    return 0;
}