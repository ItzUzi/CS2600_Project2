#include <stdio.h>
#include <stdlib.h>

/**
 * This file will take care of expenses such as meal expenses
 * and lodging expenses
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

void mealExpenseDay(short dinner, short lunch, short breakfast, int dayNumber, double meals[][3]){
    double expense;
    for (int i = 0; i < 3; i++)
    {
        meals[dayNumber][i] = 0;
    }
    
    if (breakfast == 1){
        meals[dayNumber][0] = mealExpense("breakfast", dayNumber, 9);
    }
    if (lunch == 1)
        meals[dayNumber][1] += mealExpense("lunch", dayNumber, 12);
    if(dinner == 1)
        meals[dayNumber][2] += mealExpense("dinner", dayNumber, 16);
}

/**
 * This function will calculate the meal expenses for the first
 * day of the business trip
 * Time is based on 24hr format
*/
void mealExpenseDeparture(double departure, double meals[][3], int totalDays){
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
        printf("You qualified for breakfast!\n");
    }
    if (departure < 12){
        lunch = 1;
        printf("You qualifed for lunch!\n");
    }
    if(departure < 18){
        dinner = 1;
        printf("You qualifed for dinner!\n");
    }

    for (int dayNumber = 0; dayNumber < totalDays; dayNumber++)
    {
        mealExpenseDay(dinner, lunch, breakfast, dayNumber, meals);
    }
    

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