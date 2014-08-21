// Santos Solorzano
// CSCE 206-301
// A3/7.9

// This program grades the written portion of
// a driver's license exam; it asks for user
// input and stores it in an array; it then 
// compares the user-input array to the array
// that holds the correct answers and gives
// proper feedback

#include<iostream>
#include<iomanip>
#include <cstdlib>

using namespace std;

// function prototypes
void userAnswers(char [], int);
void examResult(char [], char [], int);
void incorrect(char [], char [], int);

// global constants used for this program

// size of array
const int size = 20;

// array containing correct answers
char examAnswers[size] = {'B', 'D', 'A', 'A', 'C',
						  'A', 'B', 'A', 'C', 'D',
						  'B', 'C', 'D', 'A', 'D',
						  'C', 'C', 'B', 'D', 'A'};

int main()
{
	char studentAnswers[size]; // initialized array needed to store student's answers
	userAnswers(studentAnswers, size); // function call to input student's answers

	return 0;
}

// function that retrieves the student's answers and stores them in an array
void userAnswers(char studentAnswers[], int num1)
{
	for (int count = 0; count < num1; count++)
	{

		cout << "Question " << count + 1 << ": ";
		cin >> studentAnswers[count];

		// input validation
		if (static_cast<int>(studentAnswers[count]) < 65 || static_cast<int>(studentAnswers[count]) > 68)
			cout << "Please enter one of the following choices only: A, B, C, or D." << endl;
	}

	examResult(studentAnswers, examAnswers, size); // function call to compare answers
	incorrect(studentAnswers, examAnswers, size); // function call to display incorrectly answered questions
}

// function that determines whether or not the student passed the exam
// it also displays the number of questions answered correctly/incorrectly
void examResult(char userArray[], char examArray[], int num1)
{
	// counters used to determine how many answers were correct and incorrect
	int correct = 0;
	int incorrect = 0;

	// for loop to compare student's answers to correct answers
	for (int count = 0; count < num1; count++)
	{
		if (userArray[count] == examArray[count])
			correct++;
		else
			incorrect++;
	}

	cout << " " << endl; // formatting
	cout << "Correct answers: " << correct << endl;
	cout << "Incorrect answers: " << incorrect << endl;
	cout << " " << endl; // formatting

	if (correct >= 15)
		cout << "The student passed the test." << endl;
	else
		cout << "The student did not pass the test." << endl;
}

// this function determines and displays a list of 
// questions that the student answered incorrectly
void incorrect(char userArray[], char examArray[], int num1)
{
	cout << "Questions that were answered incorrectly:" << endl;

	// for loop that compares student's answers to correct answers
	// it then lists which question numbers were answered incorrectly
	for (int count = 0; count < num1; count++)
	{
		if (userArray[count]!= examArray[count])
			cout << count + 1 << endl;
	}
}