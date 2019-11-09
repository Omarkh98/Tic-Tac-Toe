#pragma once
#include"iostream"
#include"iomanip"
#include"stdlib.h"
#include"cstdio"
#include"ctime"
#include"string"
using namespace std;
class TicTac
{
public:
	TicTac();
	~TicTac();
	int winning();
	void chart();
	void Play(char c, int t, bool g);
	void Computer( string & l);
	void playerOne( string name1, string& l);
	void playerTwo( string name2, string& l);
	int mainMenu();
	void color();

	char TicTacToe[10] = { '0','1','2','3','4','5','6','7','8','9' };
private:
	

};

