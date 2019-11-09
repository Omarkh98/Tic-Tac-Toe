#include "TicTac.h"
#include"iostream"
#include"iomanip"
#include"stdlib.h"
#include"cstdio"
#include"ctime"
#include"string"
using namespace std;



TicTac::TicTac()
{
}


TicTac::~TicTac()
{
}

int TicTac::winning()
{
	if (TicTacToe[1] == TicTacToe[2] && TicTacToe[2] == TicTacToe[3])
		return 1;

	else if (TicTacToe[4] == TicTacToe[5] && TicTacToe[5] == TicTacToe[6])
		return 1;

	else if (TicTacToe[7] == TicTacToe[8] && TicTacToe[8] == TicTacToe[9])
		return 1;

	else if (TicTacToe[1] == TicTacToe[4] && TicTacToe[4] == TicTacToe[7])
		return 1;

	else if (TicTacToe[2] == TicTacToe[5] && TicTacToe[5] == TicTacToe[8])
		return 1;

	else if (TicTacToe[3] == TicTacToe[6] && TicTacToe[6] == TicTacToe[9])
		return 1;

	else if (TicTacToe[1] == TicTacToe[5] && TicTacToe[5] == TicTacToe[9])
		return 1;

	else if (TicTacToe[3] == TicTacToe[5] && TicTacToe[5] == TicTacToe[7])
		return 1;

	else if (TicTacToe[1] != '1' && TicTacToe[2] != '2' && TicTacToe[3] != '3'
		&& TicTacToe[4] != '4' && TicTacToe[5] != '5' && TicTacToe[6] != '6'
		&& TicTacToe[7] != '7' && TicTacToe[8] != '8' && TicTacToe[9] != '9') //Check the conditions above.
		return 0;

	else
		return -1; //Error.
}
/*
This Function is to Draw the Board of Tic Tac Toe (X-O) with player Marks
*/


void TicTac::chart()
{
	system("cls"); // Clear the Output Screen.
	cout << "Tic Tac Toe (X-O) game !" << endl;
	cout << endl;
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << TicTacToe[1] << "  |  " << TicTacToe[2] << "  |  " << TicTacToe[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << TicTacToe[4] << "  |  " << TicTacToe[5] << "  |  " << TicTacToe[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << TicTacToe[7] << "  |  " << TicTacToe[8] << "  |  " << TicTacToe[9] << endl;
	cout << "     |     |     " << endl << endl;
}

void TicTac::Play(char c, int t, bool g)
{
	if (t == 1 && TicTacToe[1] == '1')
		TicTacToe[1] = c;
	else if (t == 2 && TicTacToe[2] == '2')
		TicTacToe[2] = c;
	else if (t == 3 && TicTacToe[3] == '3')
		TicTacToe[3] = c;
	else if (t == 4 && TicTacToe[4] == '4')
		TicTacToe[4] = c;
	else if (t == 5 && TicTacToe[5] == '5')
		TicTacToe[5] = c;
	else if (t == 6 && TicTacToe[6] == '6')
		TicTacToe[6] = c;
	else if (t == 7 && TicTacToe[7] == '7')
		TicTacToe[7] = c;
	else if (t == 8 && TicTacToe[8] == '8')
		TicTacToe[8] = c;
	else if (t == 9 && TicTacToe[9] == '9')
		TicTacToe[9] = c;
	else {
		cout << "Sorry...Invalid Move!" << endl;
		if (g == true) {
			string lastPlayer = "Computer";
			Computer(lastPlayer);
		}
	}
}

void TicTac::Computer(string & l)
{
	l = "Computer";
	char c = 'O';
	int m = rand() % 9 + 1;
	Play(c, m, true);
	chart();
}

void TicTac::playerOne(string name1, string & l)
{
	l = name1;
	cout << name1 << " Please enter a Number between 1 and 9 in the Board" << endl;
	char c = 'X';
	int m; cin >> m;
	Play(c, m, false);
	chart();
}

void TicTac::playerTwo(string name2, string & l)
{
	l = name2;
	cout << name2 << " Please enter a Number between 1 and 9 in the Board" << endl;
	char c = 'O';
	int m;
	cin >> m;
	Play(c, m, false);
	chart();
}

int TicTac::mainMenu()
{

	cout << "*Press 'S' to Start the Game*\n" << endl;
	cout << "*Press 'C' to change the COLOR of the Game*\n" << endl;
	cout << "*Press 'I' for Instructions of the Game*\n" << endl;
	cout << "*Press 'Q' to Quit the Game*\n" << endl;
	char choice;
	cin >> choice;
	while (choice != 's' && choice != 'S' && choice != 'c' && choice != 'C' && choice != 'i' && choice != 'I' && choice != 'q' && choice != 'Q') {
		cout << "Invalid Input...Try Again" << endl;
		cin >> choice;
	}
	if (choice == 's' || choice == 'S') {
		system("cls");
		return 1;
	}
	else if (choice == 'c' || choice == 'C') {
		system("cls");
		color();
		// Check if the player wishes to change the COLOR of the Game again.
		system("cls");
		cout << endl;
		do {
			cout << "*Do you want to try another Color?*" << endl;
			cout << "*Press 'Y' to choose a new Color or press any Key to return to the main menu*" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y') color();
			system("cls");
		} while (choice == 'y' || choice == 'Y');

		mainMenu();
	}
	else if (choice == 'i' || choice == 'I') {
		system("cls");
		cout << "*#1 - First the player will choose whether to play against the Computer (AI) or Against another Player (Player 2)" << endl << endl;
		cout << "*#2 - Player 1 will always be X and Computer/player 2 will always be O" << endl << endl;
		cout << "*#3 - Once a player gets THREE in a row, the game will stop and the WINNER will be announced" << endl << endl;
		cout << "*#4 - Players may choose whatever color they desire for their game" << endl << endl;
		mainMenu();
	}
	else if (choice == 'q' || choice == 'Q') {
		system("cls");
		cout << "You are quitting already ? =D" << endl;
		return 0;

	}
}

void TicTac::color()
{
	system("cls");
	cout << "*Please choose a any Color you like" << endl;
	cout << endl;
	cout << "*Choose by entering the Letter of the Color" << endl;

	cout << "Choose your Color =D" << endl << endl;
	cout << "B -- BLUE" << endl;
	cout << "G -- GREEN" << endl;
	cout << "A -- AQUA" << endl;
	cout << "R -- RED" << endl;
	cout << "Y -- YELLOW" << endl;
	cout << "W -- ICE WHITE" << endl;
	cout << "P -- PURPLE" << endl;
	cout << "*Press any other Key to return to main menu" << endl;
	char color;
	cin >> color;

	// Change the Game Color.
	if (color == 'B' || color == 'b') {
		system("color 9");
	}
	else if (color == 'G' || color == 'g') { // RGB colors.
		system("color 2");
	}
	else if (color == 'A' || color == 'a') {
		system("color B");
	}
	else if (color == 'R' || color == 'r') {
		system("color 4");
	}
	else if (color == 'Y' || color == 'y') {
		system("color 6");
	}
	else if (color == 'W' || color == 'w') {
		system("color F");
	}
	else if (color == 'P' || color == 'p') {
		system("color 5");
	}
	else {
		mainMenu();
	}
}
