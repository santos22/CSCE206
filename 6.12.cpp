// Santos Solorzano
// CSCE 206-301
// A3/6.12

// This program calculates the average
// number of days a company's employees
// are absent.

#include <iostream>
#include <cstdlib>
using namespace std;

// function prototypes
int getDays();
int numDays(int);
double averageDaysMissed(int, int);


int main()
{
	int numEmp = getDays(); // function call that returns and assigns the number of employees at the company

	int totalDays = numDays(numEmp); // function call that returns and assigns the total number of days missed by the employees

	cout << "The average number of days your company's employees were absent is: " << averageDaysMissed(numEmp, totalDays) << endl; // output of the function that takes two arguments
}

// function that asks the user for the number of
// employees at the company and returns this value
// as an int
int getDays()
{
	int emp; // number of employees to be input by user

	cout << "How many employees are at the company?" << endl;
	cin >> emp;

	if (emp < 1) // input validation
	{
		cout << "The number of employees cannot be less than 1.\n"
				"Run the program again." << endl;
		exit(0); // terminates program
	}
	return emp;
}

// function that accepts the number of employees
// as one argument and asks the user the number 
// of days each employee missed during the past year
// and returns the total as an int
int numDays(int num1)
{
	int days,
		total = 0; // counter to keep track of total number of days missed

	for (int count = 0; count < num1; count++)
	{
		cout << "How many days did Employee " << count + 1 << " miss? " ;
		cin >> days;
		if (days < 0)
		{
			cout << "The number of days missed cannot be negative.\n"
					"Run the program again and enter acceptable values." << endl;
		exit(0); // terminates program
		}

		total += days;
	}

		return total;
}

// function that takes the number of employees at the company
// and the total number of days missed by all employees and
// returns the average number of days missed as a double
double averageDaysMissed(int num1, int num2)
{
	double average;
	average = static_cast<double>(num2) / num1;

	return average;
}