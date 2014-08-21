// Santos Solorzano
// CSCE 206-301

// A2/5.8
// This program displays a menu of choices
// that range from addition, subtraction,
// multiplication, and division problems
// The menu is continually displayed until
// the user chooses to quit

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	// Constants for menu choices
	const int	ADD = 1,
				SUB = 2,
				MUL = 3,
				DIV = 4,
				QUIT = 5;

	int choice;

	do
	{
		// Menu displayed to user
		cout<< "Math Tutor Menu\n"
			<< "----------------\n"
			<< "1. Addition Problem\n"
			<< "2. Subtraction Problem\n"
			<< "3. Multiplication Problem\n"
			<< "4. Division Problem\n"
			<< "5. Quit\n"
			<< "----------------\n"
			<< "Enter your choice:\n";

		cin >> choice;

		// Input validation
		while (choice < ADD || choice > QUIT)
		{
			cout << "Please enter a valid menu choice: ";
			cin >> choice;
		}

		if (choice != QUIT)
		{
			unsigned seed = time(0); // different seed to always generate distinct random numbers
			float x,y,
				answer;

			srand(seed);
			x = rand() % 500 + 1; // random numbers generated from 1 - 500
			y = rand() % 500 +1;

			switch (choice)
			{
				case ADD: 
					cout << x << " + " << y << " = ? " << endl; // random numbers displayed for addition

					cin >> answer; // user inputs answer

					if (answer == x + y)
						cout << "Spot on brother, the answer is indeed " << x + y << endl; // message displayed if answer is correct
					else
						cout << "Nope, sorry. The correct answer was " << x + y << endl; // message displayed if answer is incorrect
					break;
				case SUB: 
					cout << x << " - " << y << " = ? " << endl; // random numbers displayed for subtraction

					cin >> answer; // user inputs answer

					if (answer == x - y)
						cout << "Spot on brother, the answer is indeed " << x - y << endl; // message displayed if answer is correct
					else
						cout << "Nope, sorry. The correct answer was " << x - y << endl; // message displayed if answer is incorrect
					break;
				case MUL: 
					cout << x << " * " << y << " = ? " << endl; // random numbers displayed for multiplication

					cin >> answer; // user inputs answer

					if (answer == x * y)
						cout << "Spot on brother, the answer is indeed " << x * y << endl; // message displayed if answer is correct
					else
						cout << "Nope, sorry. The correct answer was " << x * y << endl; // message displayed if answer is incorrect
					break;
				case DIV: 
					cout << x*y << " / " << y << " = ? " << endl; // random numbers displayed for division taking into account divisibility

					cin >> answer; // user inputs answer

					if (answer == x)
						cout << "Spot on brother, the answer is indeed " << x << endl; // message displayed if answer is correct
					else
						cout << "Nope, sorry. The correct answer was " << x << endl; // message displayed if answer is incorrect
					break;
			}
		}

	} while (choice != QUIT);

	cout << "You have chosen to quit the program." << endl;

	return 0;

	}