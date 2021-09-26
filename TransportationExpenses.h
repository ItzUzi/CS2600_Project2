#include <stdio.h>
#include <stdlib.h>

/**
 * Method checks how long the trip was as well
 * how long stay is
 * Time related variables will be taken in 24 hr
 * format
 * Returns costs of airfare
 */
double airFare(int days, double arrival, double departure){



    return 0;
}

/**
 * Asks user how many miles were driven if privateVehicle returns 1
 * calculates total cost of driving while using the constant .27
 * per mile driven
 * (miles should not equal 0 if this function is called)
 * Returns total cost of driving
*/
double milesDriven(){
    //ppm = price per mile
    double miles, mileCost, ppm;
    ppm = 0.27;
    char input;

    printf("How many miles did you drive on this trip?\n");
    printf("(Input a number larger than 0)\n");
    
    scanf("%s", &input);
    miles = strtod(&input, NULL);

    if (miles <= 0 && !strtod(&input, NULL)){
        printf("Input an acceptable value!\n");
        return milesDriven();
    }
    
    mileCost = miles * ppm;

    return mileCost;
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
    printf("Did you use a private vehicle during your trip?\n(y/n)\n");

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
 * Function called if transportMethod() returns 1
 * Will calculate total cost of taxi per day
 * returns cost of taxi per day
*/
double taxi(double taxiCost[], int totalDays){
    
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

/**
 * Asks user if private car, car rental, or if taxi service was used
 * Will return total costs of transportation
*/
double transportMethod(double taxiCost[], int totalDays){
    double totalExpense = 0;
    totalExpense += privateVehicle();
    totalExpense += taxi(taxiCost, totalDays);
    return totalExpense;
}