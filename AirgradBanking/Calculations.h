/// Neal Goulas
/// CS210
/// Project 2
/// 7/31/2022
#ifndef AIRGRADBANKING_CALCULATIONS_H_
#define AIRGRADBANKING_CALCULATIONS_H_

class Calculations
{
public:
	Calculations(double t_initialInvestment, double t_interestRate, int t_numberOfYears); //Set up but didnt end up using
	Calculations(double t_initialInvestment, double t_monthlyDeposit, double t_interestRate, int t_numberOfYears); //default with all paramaters
	~Calculations(); //destructor
	void printDetailsWithoutMonthly(); //print without monthly deposit
	void printDetailsWithMonthly(); //print with monthly deposit

private:
	double initialInvestment;
	double monthlyDeposit;
	double interestRate;
	int numberOfYears;

};

#endif // !AIRGRADBANKING_CALCULATIONS_H_