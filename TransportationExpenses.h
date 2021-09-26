#include <stdio.h>
#include <stdlib.h>

/**
 * Method checks how long the trip was as well
 * how long stay is
 * Time related variables will be taken in 24 hr
 * format
 * Returns costs of airfare
 */
double airfareValidation() {
    double cost;
    printf("How much was the roundtrip airfair?");
    scanf("%lf", &cost);
    if (cost < 0){
        printf("Invalid input.\n");
        return airfareValidation();
    }   
    return cost;
}

double airfare(void){
    double cost;
    char i;

    printf("Did you travel by air? (y/n) ");
    scanf("%ls", &i);

    if (i == 'y') {
        return airfareValidation();
    }
    else if (i == 'n'){
        cost = 0;
    }
    else {
        printf("Invalid input. Try again.\n");
    }

    return cost;
}

/**
 * Asks user for value of parking fees per day
 * Calculates cost of parking fees
 * Stores values into array
 * Returns total cost of parking fees
*/
void totalParkingFees(double parkingFees[][2], int totalDays){
    short feesIndex = 1;
    short company = 6;
    double cost;
    char input;
    for(int day = 0; day < totalDays; day++){

        printf("How much were your parking fees for day %d?\n", day);
        //program crashes input is 0 or letters due to how strtod works
        printf("(If parking fee for day is 0, input -1)\n");
        printf("(If parking fees were already inputted, input -2)\n");
        printf("Covered cost is %d, if you go over you will pay the difference!\n", 6);
        scanf("%s", &input);
        cost = strtod(&input, NULL);
        if(cost == -2)
            break;
        if (cost == -1)
            cost = 0;
        if(cost < 0){
            printf("Do not input negative values!\n");
            // redoes same day in order to get acceptable value
            day--;
        }else
            parkingFees[day][feesIndex] = cost;
    }
}

/**
 * Asks user if had to pay parking fees
 * Calls parking fee total if input = y else returns 0
 * Return total cost of parking fees
*/
int parkingFees(double transportCost[][2], int totalDays){
    short feesIndex = 1;
    char input;

    printf("Did you have to pay any parking fees?\n(y/n)\n");
    scanf("%s", &input);
    
    if(input == 'y')
        totalParkingFees(transportCost, totalDays);
    else if(input == 'n')
        for (int day = 0; day < totalDays; day++)
            transportCost[day][feesIndex] = 0;
    else{
        printf("Input an acceptable value!\n");
        return parkingFees(transportCost, totalDays);
    }

    return 1;
}

/**
 * Asks user how many miles were driven if privateVehicle returns 1
 * calculates total cost of driving while using the constant .27
 * per mile driven
 * (miles should not equal 0 if this function is called)
 * Returns total cost of driving
*/
double milesDriven(double transportCost[][2], int totalDays){
    //ppm = price per mile
    double miles, mileCost, ppm, expense;
    ppm = 0.27;
    char input;

    printf("How many miles did you drive on this trip?\n");
    printf("(Input a number larger than 0)\n");
    
    scanf("%s", &input);
    miles = strtod(&input, NULL);

    if (miles <= 0 && !strtod(&input, NULL)){
        printf("Input an acceptable value!\n");
        return milesDriven(transportCost, totalDays);
    }
    mileCost = miles * ppm;
    expense = mileCost + parkingFees(transportCost, totalDays);
    return mileCost;
}
/**
 * Method asks user if they used a private vehicle 
 * throughout the trip
 * return 1 if yes private vehicle
 * return 0 if no private vehicle 
*/
double privateVehicle(double parkingFees[][2], int totalDays){
    double expense;
    char input;
    printf("Did you use a private vehicle during your trip?\n(y/n)\n");

    scanf("%s", &input);
    if (input == 'y')
        expense = milesDriven(parkingFees, totalDays);
    else if(input == 'n')
        expense = 0;
    else{
        printf("Please select acceptable answer!\n");
        return privateVehicle(parkingFees, totalDays);
    }
    return expense;
}

/**
 * Asks user for taxi cost per day
 * Puts all values into taxiCost[] in order to
 * check later on what values are covered by the company
 * Returns total cost of taxi service
*/
int totalTaxiCost(int totalDays, double taxiCost[][2]){
    double cost;
    short coveredCost = 10; 
    short taxiIndex = 0;
    char input;
    for (int day = 0; day < totalDays; day++){

    printf("\nInput ammount spent on taxi services on day %d\n", day);
    printf("(Covered cost is $%d, anything above will be reimbursed by you)\n", coveredCost);
    // if strtod returns 0, it will count as a fail and crash the program
    // Do not enter letters, will crash program
    printf("(If no taxi services were used, input -1)\n");
    scanf("%s", &input);
    cost = strtod(&input, NULL);
    if (cost == -1)
        cost = 0;
    
    // The taxiIndex is the index for the taxi in transport costs
    taxiCost[day][taxiIndex] = cost;
    }
    return 1;
}

/**
 * Function called if transportMethod() returns 1
 * Will calculate total cost of taxi per day
 * Calls taxiCost() in order to get price of taxi per day 
 * If taxi was not used, price of taxi per day = 0 
 * returns cost of taxi per day
*/
int taxi(double taxiCost[][2], int totalDays){
    short taxiIndex = 0;
    char input;
    printf("Did you use a taxi service during your trip?\n(y/n)\n");
    scanf("%s", &input);
    
    if (input == 'y')
        totalTaxiCost(totalDays, taxiCost);
    else if (input == 'n')
        for (int day = 0; day < totalDays; day++)
            taxiCost[day][taxiIndex] = 0;
    else{
        printf("Input an acceptable value!\n");
        return taxi(taxiCost, totalDays);
    }
    return 0;
}
/**
 * Calculates total cost of the car rental
 * (Car rental cost should not be zero if this function is called)
 * Returns total expense from car rental cost
*/
double carRentalCost(double parkingCost[][2], int totalDays){
    double expense = 0;
    char input;

    printf("What was the cost of the car rental service?\n");
    scanf("%s", &input);
    expense = strtod(&input, NULL);

    if (expense == 0){
        printf("Input an acceptable value!\n");
        return carRentalCost(parkingCost, totalDays);
    }

    printf("Did you acquire any parking fees?\n(y/n)\n");
    printf("(If already inputted, input n)\n");
    scanf("%s", &input);

    if (input == 'y')
        expense += parkingFees(parkingCost, totalDays);
    else if(input != 'n'){
        printf("Invalid input!\n");
        carRentalCost(parkingCost, totalDays);
    }

    return expense;
}

/**
 * Function called if transportMethod() returns 0
 * Will calculate total cost of car rental service
 * Will return cost of car rental total
*/
double carRental(double parkingFees[][2], int totalDays){
    double expense;
    char input;

    printf("Did you use a car rental service during your trip?\n(y/n)\n");
    scanf("%s", &input);

    if(input == 'y')
        expense = carRentalCost(parkingFees, totalDays);
    else if(input == 'n')
        expense = 0;
    else{
        printf("Input an acceptable value!\n");
        return carRental(parkingFees, totalDays);
    }
    return expense;
}

/**
 * Asks user if private car, car rental, or if taxi service was used
 * Will return total costs of transportation
*/
double transportMethod(double transportCost[][2], int totalDays){
    double totalExpense = 0;
    totalExpense += privateVehicle(transportCost, totalDays);
    totalExpense += carRental(transportCost, totalDays);
    taxi(transportCost, totalDays);
    return totalExpense;
}