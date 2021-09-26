#include <stdio.h>
#include <stdlib.h>

/**
 * Method checks how long the trip was as well
 * how long stay is
 * Time related variables will be taken in 24 hr
 * format
 * 
 * Returns costs of airfare
 */
double airFare(int days, double arrival, double departure){



    return 0;
}


/**
 * Asks user how many miles were driven if privateVehicle returns 1
 * calculates total cost of driving while using the constant .27
 * per mile driven
 * Returns total cost of driving
*/
double milesDriven(){
    return 0;
}
/**
 * Method asks user if they used a private vehicle 
 * throughout the trip
 * return 1 if yes private vehicle
 * return 0 if no private vehicle 
*/
double privateVehicle(){
    double expense;
    char input;
    printf("Did you have access to a private vehicle during your trip?\n(y/n)\n");

    scanf("%s", &input);
    if (input == 'y')
        expense = milesDriven();
    else if(input == 'n')
        expense = 0;
    else{
        printf("Please select acceptable answer!\n");
        return privateVehicle();
    }
    return expense;
}

/**
 * Asks user if private car, car rental, or if taxi service was used
 * Will return total costs of transportation
*/
double transportMethod(){
    double totalExpense = 0;
    totalExpense += privateVehicle();
    return totalExpense;
}

/**
 * Function called if transportMethod() returns 1
 * Will calculate total cost of taxi per day
 * returns cost of taxi per day
*/
double taxi(){
    return 0;
}

/**
 * Function called if transportMethod() returns 0
 * Will calculate total cost of car rental service
 * Will return cost of car rental total
*/
double carRental(){
    return 0;
}