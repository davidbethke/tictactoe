// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"GameType.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//GameType myGame;
	GameType myGame(2,8,8,5);
	char answer = 'y';
	do {
		myGame.play();
		cout << "Do you want to play again (y/n)? ";
		cin >> answer;
	} while(toupper(answer) == 'Y');
	return 0;
}

