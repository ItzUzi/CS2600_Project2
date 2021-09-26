#include <stdio.h>
#include <stdlib.h>

/**
 * This file will take care of expenses such as meal expenses
 * and lodging expenses using inputs taken from main as well as 
 * inputs taken within certain methods
*/

/**
 * Helper method for meal expense day meant to take in dayNumber, allowed price, and meal name
 * and let user know allowed price
 * Returns expense user paid
*/
double mealExpense(char meal[], int dayNumber, int allowedPrice){
    double expense = 0;
    char input;
    printf("Please type in the amount spent on %s on day %d of the trip.\n", meal, dayNumber);
    printf("(The allowed price for this meal is %d, anything above will be reimbursed by you)\n", allowedPrice);
    // Takes user input
    // Do not input letters or program will crash
    scanf("%s", &input);
    expense = strtod(&input, NULL);
    return expense;
}

/**
 * Takes booleans of whether user qualifies for certain meals based on their answers
 * calls mealExpense() in order to implement meal value onto array
*/
void mealExpenseDay(short dinner, short lunch, short breakfast, int dayNumber, double meals[][3]){

    if (breakfast == 1)
        meals[dayNumber][0] = mealExpense("breakfast", dayNumber, 9);
    if (lunch == 1)
        meals[dayNumber][1] = mealExpense("lunch", dayNumber, 12);
    if(dinner == 1)
        meals[dayNumber][2] = mealExpense("dinner", dayNumber, 16);
}

/**
 * Shows qualification for meals on last day with regards to the day of arrival
 * calls mealExpenseDay
*/
void mealExpenseArrival(double arrival, double meals[][3], int lastDay){
    short dinner = 0;
    short lunch = 0;
    short breakfast = 0;

    if(arrival > 8){
        breakfast = 1;
        printf("You qualified for breakfast due to your arrival time!\n");
    }else
        printf("You did not qualify for breakfast due to your arrival time!\n");
    if(arrival > 13){
        lunch = 1;
        printf("You qualified for lunch due to your arrival time!\n");
    }else
        printf("You did not qualify for lunch due to your arrival time!\n");
    if(arrival > 19){
        dinner = 1;
        printf("You qualified for dinner to your arrival time!\n");
    }else
        printf("You did not qualify for dinner due to your arrival time!\n");
    
    mealExpenseDay(dinner, lunch, breakfast, lastDay, meals);
}

/**
 * This function will calculate the meal expenses from the first
 * day of the business trip to the last
 * Time is based on 24hr format
 * Tells user whether they qualify for meals on the first day
*/
void mealExpenseDepartureToArrival(double departure, double arrival, double meals[][3], int totalDays){
    /**
     * Sets meals as 0 to substitute boolean values
     * meals = 0 are not taken into consideration
    */ 
    short dinner = 0;
    short lunch = 0;
    short breakfast = 0;

    short time1 = 7;
    short time2 = 12;
    short time3 = 18;

    /**
     * if arrival time is less than time values, 
     * user should not be able to qualify for these meals
    */
    if(totalDays == 1){
        if (arrival <= 18)
            time3 = -1;
        if(arrival <= 12)
            time2 = -1;
        if(arrival <= 7)
            time1 = -1;
    }

    //Checks departure time to see if meals are qualified
    if (departure < time1){
        breakfast = 1;
        printf("You qualified for breakfast due to your departure time\n");
    }else
        printf("You did not qualify for breakfast due to your departure time\n");
    if (departure < time2){
        lunch = 1;
        printf("You qualifed for lunch due to your departure time!\n");
    }else
        printf("You did not qualify for lunch due to your departure time!\n");
    if(departure < time3){
        dinner = 1;
        printf("You qualifed for dinner due to your departure time!\n");
    }else
        printf("You did not qualify for dinner due to your departure time!\n");

    mealExpenseDay(dinner, lunch, breakfast, 0, meals);

    for (int dayNumber = 1; dayNumber < totalDays - 1; dayNumber++)
        mealExpenseDay(1, 1, 1, dayNumber, meals);

    if(totalDays != 1)
        mealExpenseArrival(arrival, meals, totalDays - 1);
}

double registrationFees(void) {
    char i;
    double fees;
    printf("How much was spent total on conferences and seminars? ");
    scanf("%lf", &fees);
    if (fees < 0){
        printf("Invalid input.\n");
        return registrationFees();
    }
    return fees;
}

/**
 * Asks user for price per night at hotel spent
 * Lets user know the copany accepted amount
 * Returns total hotel expenses
*/
double hotelExpenses(double hotelCosts[], int totalDays){
    double cost, totalExpense;
    totalExpense = 0;
    char input[4];
    short acceptedAmount = 90;
    for (int day = 0; day < totalDays; day++){
        printf("Input amount spent on lodging on day %d.\n", day);
        printf("(The amount covered by the company is %d", 90);
        printf(", anything over will be reimbursed)\n");
        printf("(If cost of day is 0, input -1)\n");
        
        scanf("%s", input);
        cost = strtod(input, NULL);

        if (cost == -1)
            cost = 0;
        if(cost < 0){
            printf("Input an accepted value.\n");
            day--;
        }else{
        hotelCosts[day] = cost;
        totalExpense += cost;
        }
    }
    

    return totalExpense;
}

/**
 * Called to check between arrays that are based on daily values
 * Returns total expense above whats allowed by the company
*/
double reImbursementArray(double mealCost[][3], double transportPerDay[][2], double hotelCost[], int totalDays){
    double total1, total2, total3;
    double reimbursement = 0;
    // if reimbursement is positive, that is money paid
    int allowedMeals[3] = {9, 12, 16};
    int allowedTransportCost[2] = {10, 6};
    int allowedLodgingCost = 90;

    for(int day = 0; day < totalDays; day++){
        for(int meal = 0; meal < 3; meal++)
            total1 = mealCost[day][meal] - allowedMeals[meal];
        for(int index = 0; index < 2; index++)
            total2 += transportPerDay[day][index] - allowedTransportCost[index];
        total3 += hotelCost[day] - allowedLodgingCost;
        reimbursement += total1 + total2 + total3;
    }

    return reimbursement;
}


/**
 * Called to check allowable costs
 * Returns total expense allowed by the company
*/
double companyAllowedDayDependent(int totalDays){
    double allowableCost = 0;
    // Initiates arrays that will be the basis for the allowed costs
    int allowedMeals[3] = {9, 12, 16};
    int allowedTransportCost[2] = {10, 6};
    int allowedLodgingCost = 90;

    for(int day = 0; day < totalDays; day++){
        for(int meal = 0; meal < 3; meal++)
            allowableCost += allowedMeals[meal];
        for(int index = 0; index < 2; index++)
            allowableCost += allowedTransportCost[index];
        allowableCost += allowedLodgingCost;
    }

    return allowableCost;
}

/**
 * Include airfare, miles driven ect.
 * 
*/
double companyAllowedTotal(int totalDays){}

/**
 * Called if actualExpenses() return value greater
 * than allowableExpenses return value
 * Returns money business person owes company
*/
double reImbursement(int totalDays, double mealCost[][3], double transportPerDay[][2], double hotelCost[]){
    double amount;
    amount = reImbursementArray(mealCost, transportPerDay, hotelCost, totalDays);

    if(amount > 0)
        printf("You owe the company $%.2lf\n", amount);
    else if(amount == 0)
        printf("You broke even with the company!");
    else{
        amount *= -1;
        printf("You saved the company $%.2lf\n", amount);
    }
    return amount;
}
/**
 * Calculates total amount spent by business person
 * Returns total amount spent
*/
double totalCost(double totalExpenses, int totalDays, double mealCost[][3], double transportPerDay[][2], double hotelCost[]){
    printf("The total expenses ");



    return 0;
}