// Alicia & Layla's Cool Code
// ADS103
// Assessment 4
// http://www.cppforschool.com/project/tic-tac-toe-project.html
// Logic for checking wins 
// 

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include "termcolor.h"
using namespace std;
using namespace termcolor;

string squareOne = "1";
string squareTwo = "2";
string squareThree = "3";
string squareFour = "4";
string squareFive = "5";
string squareSix = "6";
string squareSeven = "7";
string squareEight = "8";
string squareNine = "9";

int winFound = 1;
int gameContinue = -1;
int gameTie = 0;

enum MenuChoice {
	PLAY_TTT = 1,
	QUIT = 2,
	CREDITS = 3,
	NO_CHOICE = -1
};

// Displays available screen to choose from (or quit)

int displayMenu()
{
	int choice = CREDITS;
	string error = "";

	do
	{
		// Beginning menu format, with colours. 
		cout << "-=-=-=-=-= " << green << "Welcome to TIC TAC TOE!" << reset << " =-=-=-=-=-\n\n";
		cout << "[  1. Play  ]" << "\n";
		cout << "[  2. Quit  ]" << "\n";
		cout << "[  3. Credits  ]" << "\n\n";
		// if there is an error, show it. 
		if (error != "")
		{
			cout << red << error;
			error = "";
		}

		cout << "[ Enter your choice ] > ";
		cin >> choice;
		cout << "\n\n\n";
		// ensure choice is valid
		// if they entered anything outside of 1,2 or 3
		// if the user choice is above 3 or below 1, it's an error

		if (choice < 1 || choice > 3)
		{
			error = "[ ERROR! Only 1, 2 or 3 accepted. Don't kill the beep boop bot! ]\n\n";
			system("cls");
		}

		// otherwise, return choice.

	} while (error != ""); // While there is an error / error isn't empty
	return choice;
}

void drawTTT()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << squareOne << "  |  " << squareTwo << "  |  " << squareThree << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << squareFour << "  |  " << squareFive << "  |  " << squareSix << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << squareSeven << "  |  " << squareEight << "  |  " << squareNine << endl;

	cout << "     |     |     " << endl << endl;
}

int checkForWins() {

	if (squareOne == squareTwo && squareTwo == squareThree)

		return winFound;
	else if (squareFour == squareFive && squareFive == squareSix)

		return winFound;
	else if (squareSeven == squareEight && squareEight == squareNine)

		return winFound;
	else if (squareOne == squareFour && squareFour == squareSeven)

		return winFound;
	else if (squareTwo == squareFive && squareFive == squareEight)

		return winFound;
	else if (squareThree == squareSix && squareSix == squareNine)

		return winFound;
	else if (squareOne == squareFive && squareFive == squareNine)

		return winFound;
	else if (squareThree == squareFive && squareFive == squareSeven)

		return winFound;
	else if (squareOne != "1" && squareTwo != "2" && squareThree != "3"
		&& squareFour != "4" && squareFive != "5" && squareSix != "6"
		&& squareSeven != "7" && squareEight != "8" && squareNine != "9")

		return gameTie;
	else
		return gameContinue;

}

void boardReset() {

	squareOne = "1";
	squareTwo = "2";
	squareThree = "3";
	squareFour = "4";
	squareFive = "5";
	squareSix = "6";
	squareSeven = "7";
	squareEight = "8";
	squareNine = "9";
}


int playTicTacToe()
{
	int player = 1, i, choice;
	char mark;
	int compChoice = 0;
	int playerChoice = 2;

	// Initialising the Tic Tac Toe function.
	// First, asking which game the player wants.

	cout << "\n[ What game mode?]";
	cout << "\n";
	cout << "\n[ 1. Player verses Player ]";
	cout << "\n[ 2. Player verses Computer ]";
	cout << "\n\n";
	cin >> playerChoice;
	cout << "\n[ Loading... ]";
	Sleep(2000);

	if (playerChoice == 1 && gameContinue == -1)
	{
		do
		{
			system("cls");

			cout << "\n[ Player verses Player. ]";

			drawTTT();
			player = (player % 2) ? 1 : 2;
			cout << "Player " << player << ", enter a number:  ";
			cin >> choice;

			mark = (player == 1) ? 'X' : 'O';

			if (choice == 1 && squareOne == "1")

				squareOne = mark;
			else if (choice == 2 && squareTwo == "2")

				squareTwo = mark;
			else if (choice == 3 && squareThree == "3")

				squareThree = mark;
			else if (choice == 4 && squareFour == "4")

				squareFour = mark;
			else if (choice == 5 && squareFive == "5")

				squareFive = mark;
			else if (choice == 6 && squareSix == "6")

				squareSix = mark;
			else if (choice == 7 && squareSeven == "7")

				squareSeven = mark;
			else if (choice == 8 && squareEight == "8")

				squareEight = mark;
			else if (choice == 9 && squareNine == "9")

				squareNine = mark;
			else
			{
				cout << "Invalid move ";

				player--;
				cin.ignore();
				cin.get();
			}
			i = checkForWins();

			player++;
		} while (i == -1);

		drawTTT();
		if (i == 1)
			cout << green << "\n[ You've got some skill, Player " << --player << "! ]\n\n";
		else
			cout << red << "\n[ Tie! Better luck next time! ]";

		boardReset();

	}


	else if (playerChoice == 2 && gameContinue == -1)
	{
		do
		{
			system("cls");

			cout << "\n[ Player verses Computer. ]";

			drawTTT();
			player = (player % 2) ? 1 : 2;
			mark = (player == 1) ? 'X' : 'O';

			if (player == 1)
			{
				cout << "Player " << player << ", enter a number:  ";
				cin >> choice;


				if (choice == 1 && squareOne == "1")

					squareOne = mark;
				else if (choice == 2 && squareTwo == "2")

					squareTwo = mark;
				else if (choice == 3 && squareThree == "3")

					squareThree = mark;
				else if (choice == 4 && squareFour == "4")

					squareFour = mark;
				else if (choice == 5 && squareFive == "5")

					squareFive = mark;
				else if (choice == 6 && squareSix == "6")

					squareSix = mark;
				else if (choice == 7 && squareSeven == "7")

					squareSeven = mark;
				else if (choice == 8 && squareEight == "8")

					squareEight = mark;
				else if (choice == 9 && squareNine == "9")

					squareNine = mark;
				else
				{
					cout << "Invalid move ";

					player--;
					cin.ignore();
					cin.get();
				}
			}

			if (player == 2) {

				compChoice = rand() % 9 + 1;

				if (compChoice == 1 && squareOne == "1")

					squareOne = mark;
				else if (compChoice == 2 && squareTwo == "2")

					squareTwo = mark;
				else if (compChoice == 3 && squareThree == "3")

					squareThree = mark;
				else if (compChoice == 4 && squareFour == "4")

					squareFour = mark;
				else if (compChoice == 5 && squareFive == "5")

					squareFive = mark;
				else if (compChoice == 6 && squareSix == "6")

					squareSix = mark;
				else if (compChoice == 7 && squareSeven == "7")

					squareSeven = mark;
				else if (compChoice == 8 && squareEight == "8")

					squareEight = mark;
				else if (compChoice == 9 && squareNine == "9")

					squareNine = mark;
				/*else if(choice is already chosen){
					
					// chose another rand number
				} */
			}

			i = checkForWins();

			player++;
		} while (i == -1);
		drawTTT();
		if (i == 1)

			cout << green << "\n[ You've got some skill, Player " << --player << "! ]\n\n";
		else
			cout << red << "\n[ Tie! Better luck next time! ]";

		boardReset();

	}

	cout << white << on_blue << "\n[ -= Press any key to return to the menu... =-]\n" << reset;
	_getch();
	return winFound;
}

// Display info about the makers of Seven Seas Spin!

void displayCredits()
{
	// A new screen that shows a few lines containing people with, stupid, silly little names.
	cout << "\n\n";
	cout << cyan << " [ -=-=-=-=-=-=-=-=-=-=-=-=-=- ] \n";
	cout << " [ " << white << "Developed by ...            " << cyan << "] \n";
	Sleep(300);
	cout << " [                             ] \n";
	Sleep(300);
	cout << " [ \t" << white << " *Drum roll...*        " << cyan << "] \n";
	cout << " [                             ] \n";
	cout << " [       " << yellow << "     Alicia McEwen    " << cyan << "] \n";
	cout << " [                     &       ] \n";
	cout << " [       " << yellow << "    Layla Darwiche    " << cyan << "] \n";
	cout << cyan << " [ -=-=-=-=-=-=-=-=-=-=-=-=-=- ] \n";
	Sleep(2000);
	// Sleep functions are to hold the player's attention, make it seem more like credits each time. 
	// Once done, display a message "Hit any key to return to menu."
	// Wait for that keypress before ending function.

	cout << blue << "\n[ Press any key to return to the menu ... ]\n" << reset;
	_getch();
}


void displayQuit()
{
	cout << blue << "\n[ See you next time ... ]\n";

	cout << blue << "\n[ Press any key to quit ]\n";
	_getch();

	return;
}

int main()
{
	int choice = NO_CHOICE;

	do
	{
		system("cls");
		choice = displayMenu();

		if (choice == PLAY_TTT)
		{
			system("cls");
			playTicTacToe();
		}
		else if (choice == CREDITS)
		{
			system("cls");
			displayCredits();
		}
	} while (choice != QUIT);
	//loop while the player choice isn't quit

	system("cls");
	displayQuit();
}