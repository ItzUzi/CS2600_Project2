#include <stdio.h>
#include <stdlib.h>

/**
 * This file will take care of expenses such as meal expenses
 * and lodging expenses
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

void mealExpenseArrival(double arrival, double meals[][3], int totalDays){
    short dinner = 0;
    short lunch = 0;
    short breakfast = 0;

    if(arrival > 8){
        breakfast = 1;
        printf("You qualified for breakfast due to your arrival time!\n");
    }
    if(arrival > 13){
        lunch = 1;
        printf("You qualified for lunch due to your arrival time!\n");
    }
    if(arrival > 19){
        dinner = 1;
        printf("You qualified for dinner to your arrival time!\n");
    }
    
    mealExpenseDay(dinner, lunch, breakfast, totalDays, meals);
}

/**
 * This function will calculate the meal expenses for the first
 * day of the business trip
 * Time is based on 24hr format
*/
void mealExpenseDepartureAndArrival(double departure, double arrival, double meals[][3], int totalDays){
    /**
     * Sets meals as 0 to substitute boolean values
     * meals = 0 are not taken into consideration
    */ 
    short dinner = 0;
    short lunch = 0;
    short breakfast = 0;

    //Checks departure time to see if meals are qualified
    if (departure < 7){
        breakfast = 1;
        printf("You qualified for breakfast due to your departure time\n");
    }
    if (departure < 12){
        lunch = 1;
        printf("You qualifed for lunch due to your departure time!\n");
    }
    if(departure < 18){
        dinner = 1;
        printf("You qualifed for dinner due to your departure time!\n");
    }

    for (int dayNumber = 0; dayNumber < totalDays - 1; dayNumber++)
    {
        mealExpenseDay(dinner, lunch, breakfast, dayNumber, meals);
    }

    mealExpenseArrival(arrival, meals, totalDays - 1);
}


/**
 * Calculates total expenses that will be covered by company
 * returns total expenses company will pay for
*/
double allowableExpenses(int days, double departure, double arrival){
    return 0;
}

/**
 * Calculates total expenses accrued by business person
 * returns total expenses acrued by business person
*/
double actualExpenses(){
    return 0;
}

/**
 * Called if actualExpenses() return value greater
 * than allowableExpenses return value
 * Returns money business person owes company
*/
double reImbursement(){
    return 0;
} 