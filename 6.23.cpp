// Santos Solorzano
// CSCE 206-301
// A3/6.23

// This program lets the user play the game
// Rock, Paper, Scissors against the computer

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
int getUserChoice();
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);

int main()
{
	int human, // variables used to assign user and computer choices
		comp;

	// do while loop that lets the user keep playing until he or she quits
	do
	{
	human = getUserChoice(); // value returned by this function represents either paper, rock, or scissors for the user
	comp = getComputerChoice(); // value returned by this function represents either paper, rock, or scissors for the computer

	cout << " " << endl; // formatting

	determineWinner(human, comp); // function call displays the results and the winner
	
	} while (human != 4); // loops until condition is true
	cout << "And you have chosen to quit the game! See you next time!" << endl;

}

// function that allows a user to
// input his or her choice of "rock",
// "paper", or "scissors"; his or her
// choice is returned
int getUserChoice()
{
	int choice;

	// Menu displayed to user
	cout << "Game Menu\n"
		<< "----------\n"
		<< "1. Rock\n"
		<< "2. Paper\n"
		<< "3. Scissors\n"
		<< "4. Quit\n"
		<< " \n"
		<< "Enter your choice:\n";

	cin >> choice;

	cout << " " << endl; // formatting

	// outputs user choice on screen
	if (choice == 1)
		cout << "You have chosen rock." << endl;
	if (choice == 2)
		cout << "You have chosen paper." << endl;
	if (choice == 3)
		cout << "You have chosen scissors." << endl;

	return choice;
}

// this function allows a random number from
// 1 to 3 to be generated when the program
// starts; the number corresponds to the
// menu above and represents the
// computer's choice in the game, respectively
int getComputerChoice()
{
	unsigned seed = time(0);
	int x;

	srand(seed);
	x = rand() % 3 + 1; // generates a random number from 1 to 3

	// outputs computer's choice on screen
	if (x == 1)
		cout << "The computer has chosen rock." << endl;
	if (x == 2)
		cout << "The computer has chosen paper." << endl;
	if (x == 3)
		cout << "The computer has chosen scissors." << endl;

	return x;
}

// function that consists of lots of if
// statements to determine the results
// and who wins out of the computer
// and the human
void determineWinner(int num1, int num2)
{
	if (num1 == num2)
		cout << "It's a tie!" << endl;

	if (num1 == 1 && num2 == 2)
		cout << "Computer wins! Paper wraps rock." << endl;
	if (num1 == 1 && num2 == 3)
		cout << "You win! The rock smashes the scissors." << endl;

	if (num1 == 2 && num2 == 1)
		cout << "You win! Paper wraps rock." << endl;
	if (num1 == 2 && num2 == 3)
		cout << "Computer wins! Scissors cuts paper." << endl;

	if (num1 == 3 && num2 == 1)
		cout << "Computer wins! The rock smashes the scissors." << endl;
	if (num1 == 3 && num2 == 2)
		cout << "You win! Scissors cuts paper." << endl;

	cout << " " << endl; // formatting
}