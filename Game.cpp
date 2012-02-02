// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"GameType.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	GameParameters myGameParams;
	//GameType myGame;
	GameType myGame(myGameParams);
	char answer = 'y';
	do {
		myGame.play();
		cout << "Do you want to play again (y/n)? ";
		cin >> answer;
	} while(toupper(answer) == 'Y');
	return 0;
}

