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
 * Asks user for value of parking fees per day
 * Calculates cost of parking fees
 * Stores values into array
 * Returns total cost of parking fees
*/
double totalParkingFees(double parkingFees[][2], int totalDays){
    short feesIndex = 1;
    short company = 6;
    double totalExpense, cost;
    totalExpense = 0;
    char input;
    printf("Made it to line 30\n");
    for(int day = 0; day < totalDays; day++){

        printf("How much were your parking fees for day %d?\n", day);
        //program crashes input is 0 due to how strtod works
        printf("(If parking fee for day is 0, input -1)\n");
        printf("Covered cost is %d, if you go over you will pay the difference!\n", company);
        scanf("%s", &input);
        cost = strtod(&input, NULL);
        if (cost == -1)
            cost = 0;
        if(cost < 0){
            printf("Do not input negative values!");
            // redoes same day in order to get acceptable value
            day--;
            totalParkingFees(parkingFees, totalDays);
        }else{
            parkingFees[day][feesIndex] = cost;
            totalExpense += cost;
        }
    }
    return totalExpense;
}

/**
 * Asks user if had to pay parking fees
 * Calls parking fee total if input = y else returns 0
 * Return total cost of parking fees
*/
double parkingFees(double transportCost[][2], int totalDays){
    short feesIndex = 1;
    double fees;
    char input;

    printf("Did you have to pay any parking fees?\n(y/n)\n");

    scanf("%s", &input);
    printf("Made it to line 66\n");
    if(input == 'y')
        fees = totalParkingFees(transportCost, totalDays);
    else if(input == 'n'){
        for (int day = 0; day < totalDays; day++)
            transportCost[day][feesIndex] = 0;
        fees = 0;
    }
    else{
        printf("Input an acceptable value!\n");
        return parkingFees(transportCost, totalDays);
    }

    return fees;
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
double totalTaxiCost(int totalDays, double taxiCost[][2]){
    double expense, cost;
    short coveredCost = 6; 
    short taxiIndex = 0;
    char input;
    expense = 0;
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
    expense += cost;
    }
    return expense;
}

/**
 * Function called if transportMethod() returns 1
 * Will calculate total cost of taxi per day
 * Calls taxiCost() in order to get price of taxi per day 
 * If taxi was not used, price of taxi per day = 0 
 * returns cost of taxi per day
*/
double taxi(double taxiCost[][2], int totalDays){
    short taxiIndex = 0;
    double expense = 0;
    char input;
    printf("Did you use a taxi service during your trip?\n(y/n)\n");
    scanf("%s", &input);
    
    if (input == 'y')
        expense = totalTaxiCost(totalDays, taxiCost);
    else if (input == 'n')
        for (int day = 0; day < totalDays; day++)
            taxiCost[day][taxiIndex] = 0;
    else{
        printf("Input an acceptable value!\n");
        return taxi(taxiCost, totalDays);
    }
    return expense;
}
/**
 * Calculates total cost of the car rental
 * (Car rental cost should not be zero if this function is called)
 * Returns total expense from car rental cost
*/
double carRentalCost(){
    double expense;
    char input;

    printf("What was the cost of the car rental service?\n");
    scanf("%s", &input);
    expense = strtod(&input, NULL);

    if (expense == 0){
        printf("Input an acceptable value!\n");
        return carRentalCost();
    }

    return expense;
}

/**
 * Function called if transportMethod() returns 0
 * Will calculate total cost of car rental service
 * Will return cost of car rental total
*/
double carRental(){
    double expense;
    char input;

    printf("Did you use a car rental service during your trip?\n(y/n)\n");
    scanf("%s", &input);

    if(input == 'y')
        expense = carRentalCost();
    else if(input == 'n')
        expense = 0;
    else{
        printf("Input an acceptable value!\n");
        return carRental();
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
    totalExpense += taxi(transportCost, totalDays);
    return totalExpense;
}