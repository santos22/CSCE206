// Santos Solorzano
// CSCE 206-301
// A2/5.20

// This program generates a random number
// and prompts the user to guess what it is. It states 
// if the number guessed was too high or too low
// after every iteration, and loops
// until the number is guessed correctly

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int guess,
		random_number;
	unsigned seed = time(0);

	srand(seed);
	random_number = rand();

	cout << random_number << endl; // displays random number just to see what it is

	do
	{
		cout << "Can you guess what my number is?" << endl; //prompt
		cin >> guess;

		if (guess > random_number)
			cout << "Too high, try again." << endl;
		if (guess < random_number)
			cout << "Too low, try again." << endl;

	} while (guess != random_number);

	cout << "You have correctly guessed my number, which was " << random_number << "!" << endl;

	return 0;

}