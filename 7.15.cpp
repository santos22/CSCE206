// Santos Solorzano
// CSCE 206-301
// A3/7.15

// This program allows two players to play
// a game of tic-tac-toe, and then displays
// if there was a tie or if player X/player O
// won the game

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// global constants used
const int ROW = 3; // number of rows in the tic-tac-toe table
const int COL = 3; // number of columns in the tic-tac-toe table

// function prototypes
void dispBoard(char array[][COL], int row, int col);
void playerX(char array[][COL]);
void playerO(char array[][COL]);
bool gameResult(char array[][COL], char c);

int main()
{
	// 3x3 tic-tac-toe board array
    char game[3][3] = {{'*','*','*'},
                       {'*','*','*'},
                       {'*','*','*'}};
	int turn = 0; // counter for the number of turns after X and O make their move

	dispBoard(game, ROW, COL); // function call that displays board

	// while loop that loops through the turns until there is a winner/tie
	while (turn != 4)
	{
		playerX(game);

		playerO(game);

		turn++; // increments number of turns
	}
	cout << "The game will be a tie!" << endl;

	return 0;
}

// function to display board with interactive information
void dispBoard(char array[][COL], int row, int col)
{
	cout << "      Columns" << endl;
	cout << "       1 " << "2 " << "3 " << endl;
	for (int x = 0; x < row; x++)
	{
		cout << "Row " << x + 1 << ": ";
		for (int y = 0; y < col; y++)
		{
			cout << array[x][y] << " ";
		}
		cout << endl;
	}
}

// function for player X's turn
void playerX(char array[][COL])
{
        char move1 = 'X';
		int row, col;
        
		// interactive info for the player to make his or her move
		cout << "Player X, pick a row..." << endl;
		cin >> row;
		cout << "Player X, pick a col..." << endl;
		cin >> col;
		array[row-1][col-1] = move1;

		dispBoard(array, ROW, COL); // function call that shows updated board after move

		// if statement that displays if player X won the game
		if (gameResult(array, move1) == 1)
		{
			cout << "Player X wins!" << endl;
			exit(0);
		}
}

// function for player O's turn
void playerO(char array[][COL])
{
        char move2 = 'O';
		int row, col;
        
		// interactive info for the player to make his or her move
        cout << "Player O, pick a row..." << endl;
		cin >> row;
		cout << "Player O, pick a col..." << endl;
		cin >> col;
		array[row-1][col-1] = move2;

		dispBoard(array, ROW, COL); // function call that shows updated board after move

		// if statement that displays if player O won the game
		if (gameResult(array, move2) == 1)
		{
			cout << "Player O wins!" << endl;
			exit(0);
		}
}

// function that determines whether or not there was a winner
bool gameResult(char array[][COL], char c)
{
	// if statements that check board positions and combinations that win the game
	if ((array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] == c) ||

	(array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] == c) ||

	(array[0][0] == array[1][0] && array[1][0] == array[2][0] && array[0][0] == c) ||

	(array[0][1] == array[1][1] && array[1][1] == array[2][1] && array[0][1] == c) ||

	(array[0][2] == array[1][2] && array[1][2] == array[2][2] && array[0][2] == c) ||

	(array[2][0] == array[2][1] && array[2][1] == array[2][2] && array[2][0] == c) ||

	(array[1][0] == array[1][1] && array[1][1] == array[1][2] && array[1][0] == c) ||

	(array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] == c))

	{
	return true;
	}
}