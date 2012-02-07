// Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"GameType.h"
#include "GameParameters.h"
#include "gtest/gtest.h"
using namespace std;
TEST(SampleTest,test1)
{
	EXPECT_EQ(1,1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
	std::getchar();
	//temp disable game for tests
	GameParameters myGameParams(15,15,5); //default to 3x3 tic tac toe
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

