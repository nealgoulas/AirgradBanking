/// Neal Goulas
/// CS210
/// Project 2
/// 7/31/2022

#include <iostream>
#include "Calculations.h"

using namespace std;

int main()
{
    while (1)
    {
        //declare variables to hold input
        double investment;
        double monthlyDeposit;
        double interestRate;
        int years;

        //Output the initial header for the user
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        cout << endl;


        //Get user input
        cout << "*************************************" << endl;
        cout << "*************Data Input**************" << endl;

        cout << "Initial Investment Amount: $";
        cin >> investment;
  
        cout << "Monthly Deposit: $";
        cin >> monthlyDeposit;

        cout << "Annual Interest: %";
        cin >> interestRate;

        cout << "Number of years: ";
        cin >> years;

        //Create our object for our calculations
        Calculations calculate = Calculations(investment, monthlyDeposit, interestRate, years);
        cout << endl;

        //Call the report without the monthly info
        calculate.printDetailsWithoutMonthly();
        cout << endl;

        //Call the monthly report if a monthly deposit over zero was made
        if (monthlyDeposit > 0) 
        {
            calculate.printDetailsWithMonthly();
        }

        //Run another report if the user would like
        cout << endl << "Do you want to print another report? (y/n): ";

        string choice;
        cin >> choice;

        if (choice == "n" || choice == "N") 
        {
            break;
        }

        cout << endl;

    }
}

