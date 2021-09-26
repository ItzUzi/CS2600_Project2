#include <stdio.h>
#include "DatesAndTime.h"
#include "StayExpense.h"

/**
 * Program will run from here, this method will make calls
 * to other methods in order recieve all travel expenses
*/



int main(int argc, char *argv[])
{
    int amountOfDays;
    double departure, arrival;
    printf("Hello welcome to the Travel Expense calculator\n");
    departure = setTime("Departure");
    arrival = setTime("Arrival");
    amountOfDays = daysOnTrip();

    // creates array showing all meals, as well as differentiating between meals
    double meals[amountOfDays][3];

    mealExpenseDepartureAndArrival(departure, arrival, meals, amountOfDays);

    for (int i = 0; i < amountOfDays; i++)
    {
       for(int j = 0; j < 3; j++){
           printf("Meal cost is $%.2lf\n", meals[i][j]);
       }
    }
    



    return 0;
}
