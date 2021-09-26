#include <stdio.h>
#include "DatesAndTime.h"
#include "StayExpense.h"
#include "TransportationExpenses.h"

/**
 * Program will run from here, this method will make calls
 * to other methods in order recieve all travel expenses
*/
int main(int argc, char *argv[])
{
    int amountOfDays;
    //expenses are company allowed, Not day dependent ie: airfare, miles driven
    double departure, arrival, transportCost, expenses, stayingFees, airfareCost, registrationCost;
    expenses = 0;
    stayingFees = 0;
    printf("Hello welcome to the Travel Expense calculator\n");
    
    // Function for setting how many days were spent on the trip
    amountOfDays = daysOnTrip();
    // Functions for setting the time of departure and time of arrival, respectively. 
    departure = setTime("Departure");
    arrival = setTime("Arrival");

    if(amountOfDays == 1 && departure >= arrival)
       while (departure >= arrival)
        {
            printf("\nDeparture and arrival time are not acceptable.\n");
            printf("Please use acceptable departure and arrival times.\n");
            departure = setTime("Departure");
            arrival = setTime("Arrival");
        }

    // Function for setting airfare costs
    airfareCost = airfare();

    // creates array showing all meals, as well as differentiating between meals
    double meals[amountOfDays][3];
    mealExpenseDepartureToArrival(departure, arrival, meals, amountOfDays);

    for (int i = 0; i < amountOfDays; i++)
    {
       for(int j = 0; j < 3; j++){
           printf("Meal cost is $%.2lf\n", meals[i][j]);
       }
    }

    // Function for setting registration costs
    registrationCost = registrationFees();

    int taxiCost = 0; 
    int parkingFees = 0;
    // Only takes into consideration the fees the company takes care of based on daily values
    double transportationCost[amountOfDays][2];
    transportCost = transportMethod(transportationCost, amountOfDays);
    printf("Total transport cost: $%.2lf\n", transportCost);

    double hotelCost[amountOfDays];
    double lodgingCosts = hotelExpenses(hotelCost, amountOfDays); 
    printf("total lodging is: $%.2lf\n", lodgingCosts);
    return 0;
}
