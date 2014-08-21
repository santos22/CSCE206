// Santos Solorzano
// CSCE 206-301
// A2/4.5

// This program calculates and displays a person's
// body mass index (BMI), and displays the category
// they fall under when compared to standards

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int weight; // weight of an individual measured in pounds (lbs)
	int height; // height of an individual measured in inches 
	float BMI; // body mass index

	cout << "What is your body weight?" << endl;
	cin >> weight;

	cout << "What is your body height?" << endl;
	cin >> height;

	BMI = (weight*703)/(pow(height, 2.0)); // BMI equation
	
	if (18.5 < BMI && 25 > BMI)
	{
		cout << "You have optimal weight!" << endl;
	}

	else
	{
		if (BMI < 18.5) // checks if underweight
		{
			cout << "Your BMI is "<< setprecision(2) << fixed << BMI << ", which means you are underweight." << endl;
		}
		else if (BMI > 25) // checks if overweight
			cout << "Your BMI is "<< setprecision(2) << fixed << BMI << ", which means you are overweight." << endl;
	}

	return 0;
}