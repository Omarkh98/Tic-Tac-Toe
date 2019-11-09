#include"iostream"
#include"iomanip"
#include"stdlib.h"
#include"cstdio"
#include"ctime"
#include"string"
#include "TicTac.h"
using namespace std;


int main() {
	TicTac XO;
	cout << "\n\n*WELCOME to TIC TAC TOE game!*\n\n\n\n";
	if (XO.mainMenu() == 0) {
		return 0;
	}
	int player = 1, i, choice;
	srand(time(NULL));
	char check, game;
	bool gamemode;
	string name1;
	string name2;
	string lastPlayer;
	bool play = true;

	cout << "Would you Like to Play against the Computer (AI) or against another 'Human' player ?" << endl << endl;
	cout << "Enter 'C' for Computer and 'H' for Human" << endl;
	cin >> game;
	while (game != 'H' && game != 'C' && game != 'c' && game != 'h') {
		cout << "Invalid input, try again" << endl;
		cin >> game;
	}
	if (game == 'C' || game == 'c') {
		gamemode = true;
	}
	else if (game == 'H' || game == 'h') {
		gamemode = false;
	}
	if (gamemode == true) {
		cout << "Player...Please enter your Name" << endl;
		cin >> name1;
	}
	else {
		cout << "\n\nPlayer 1 please enter your Name" << endl;
		cin >> name1;
		cout << "\n\nPlayer 2 please enter your Name" << endl;
		cin >> name2;
	}
	XO.chart();
	while (play) {
		for (int i = 0; i < 10; i++) {
			XO.TicTacToe[i] = char(int('0') + i);
		}
		XO.chart();
		do {
			XO.playerOne(name1, lastPlayer);
			i = XO.winning();
			if (i == 1 || i == 0) break;
			(gamemode == true) ? XO.Computer(lastPlayer) : XO.playerTwo(name2, lastPlayer);
			i = XO.winning();

		} while (i == -1);
		XO.chart();
		if (i == 1)
			cout << lastPlayer << " WINSS!!" << endl;
		else {
			cout << "The Game is a TIE!" << endl;
		}
		cout << "Would you like to play again ?( Y  or N )" << endl;
		char choice;
		cin >> choice;
		while (choice != 'N' && choice != 'n' && choice != 'y' && choice != 'Y') {
			cout << "Invalid Input" << endl;
			cin >> choice;
		}
		if (choice == 'N' || choice == 'n') {
			play = false;
		}
	}
	system("pause");
	return 0;
}
/*
This Function is to return the game STATUS as 1 (game is over with a Result), and -1 ( game is over but with 0 or No Result).
*/






	







