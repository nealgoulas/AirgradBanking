/// Neal Goulas
/// CS210
/// Project 2
/// 7/31/2022
#include "Calculations.h"
#include <iomanip>
#include <iostream>
using namespace std;

/// <summary>
/// Constructor for no monthly deposits
/// </summary>
/// <param name="t_initialInvestment"></param>
/// <param name="t_interestRate"></param>
/// <param name="t_numberOfYears"></param>
Calculations::Calculations(double t_initialInvestment, double t_interestRate, int t_numberOfYears)
{
    this->initialInvestment = t_initialInvestment;
    this->interestRate = t_interestRate;
    this->numberOfYears = t_numberOfYears;
}

/// <summary>
/// constructor with monthly deposits
/// </summary>
/// <param name="t_initialInvestment"></param>
/// <param name="t_monthlyDeposit"></param>
/// <param name="t_interestRate"></param>
/// <param name="t_numberOfYears"></param>
Calculations::Calculations(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears)
{
    this->initialInvestment = t_initialInvestment;
    this->interestRate = t_interestRate;
    this->numberOfYears = t_numberOfYears;
    this->monthlyDeposit = t_monthlyDeposit;
}

/// <summary>
/// Destructor
/// </summary>
Calculations::~Calculations()
{
}

/// <summary>
/// Print The reports
/// </summary>
void Calculations::printDetailsWithoutMonthly()
{
    //Display the Report Header
    cout << " Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;


    //Set initial year
    int currentyear = 1;

    //variable to hold the year balance
    double yearBalance = this->initialInvestment;


    //loop through the amount of years
    while (currentyear <= this->numberOfYears)
    {

        //Calculate interest
        double interestEarned = yearBalance * this->interestRate / 100;

        //Add it to yearBalance
        yearBalance += interestEarned;

        //Output the results the results for each year
        cout << right << setw(10) << currentyear << fixed << setprecision(2) << setw(20) << yearBalance << setw(35) << interestEarned << endl;

        //Increase the year by one
        currentyear++;
    }
}


/// <summary>
/// Print details with monthly deposits
/// </summary>
void Calculations::printDetailsWithMonthly()
{
    //Display the Report Header
    cout << " Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "==========================================================================" << endl;
    cout << setw(10) << "Year" << setw(20) << "Year End Balance" << setw(35) << "Year End Earned Interest Rate" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    //Initialize the current year
    int currentyear = 1;

    //variable to hold the year balance initialized with the initial investment
    double yearBalance = this->initialInvestment;


    // loop through the years calulate the interest monthly and find the compoud interest
    while (currentyear <= this->numberOfYears) 
    {
        //initialize the current month
        int month = 1;

        //variable to hold the interest earned
        double interestEarned = 0.0;

        //variable for the monthly balance init to the year balance to start
        double monthBalance = yearBalance;

        while (month <= 12) 
        {
            //Add the monthly deposit
            monthBalance += this->monthlyDeposit;

            //Calculate the monthly interest
            double monthlyinterest = monthBalance * this->interestRate / (100 * 12);

            //Add the monthly interest to the yearly interest
            interestEarned += monthlyinterest;

            //Add the interest to the month balance
            monthBalance += monthlyinterest;

            //Increase the month
            month++;
        }

        //After A year has looped through set the year balance
        yearBalance = monthBalance;

        //Output the year to the report
        cout << right << setw(10) << currentyear << fixed << setprecision(2) << setw(20) << yearBalance << setw(35) << interestEarned << endl;

        //Add the next year
        currentyear++;
    }
}