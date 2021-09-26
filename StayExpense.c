#include <stdio.h>

/**
 * This file will take care of expenses such as meal expenses
 * and lodging expenses
*/

/**
 * This function will calculate the meal expenses for the first
 * day of the business trip
*/
double mealExpenseDeparture(double departure){
    double expense = 0;
    short dinner, lunch, breakfast;
    if(departure < 18)
        dinner = 1;

    return expense;
}

double mealExpenseArrival(double arrival){
    return 0.0;
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