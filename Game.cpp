// Game.cpp : Defines the entry point for the console application.
//	Advanced C++ Class
//  Assignment 2:
//	David Bethke
//	Works for tic,tac,toe
//	Works for custom boards > 3,3 rectangular or square, any number in a Row to win < max(row,col)
//	Works for swapping player order
//	Works for computer players
//	Commented Out DEBUG/NDEBUG stuff, compiled for me, if not turn on  /FORCE:MULTIPLE  /ignore:4006 in linker command line opts
//	DEBUG build, 
//	#define _DEBUG
//	#undef NDEBUG
//	Release Build
//	#undef _DEBUG
//	#define NDEBUG


#include "stdafx.h"
#include<iostream>
#include"GameType.h"
#include "GameParameters.h"
/*
#ifdef _DEBUG
#include "gtest/gtest.h"


TEST(SampleTest,test1)
{
	EXPECT_EQ(1,1);
}
#endif //_DEBUG
*/
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	/*enable only for  DEBUG
	#ifdef _DEBUG
	testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
	std::getchar();
	#endif
	*/
	//choose game
//#ifdef NDEBUG
	char gameAnswer='n';
	int gameRows=3, gameCols=3, gameInARow=3; //default to tic tac toe
	
	cout << "Custom game (y) or Tic Tac Toe game(n)"<<endl;
	cin >>gameAnswer;
	if(gameAnswer=='y')
	{
		cout <<"Enter your response carefully, there is no error checking"<<endl;
		cout <<"Number of Rows in the Board"<<endl;
		cin>>gameRows;
		cout <<"Number of Cols in the Board"<<endl;
		cin>>gameCols;
		cout <<"Number of Marks in A Row to Win"<<endl;
		cin>>gameInARow;
		
		
	}

	GameParameters myGameParams(gameRows,gameCols,gameInARow);
	GameType myGame(myGameParams);
	//#endif //NDEBUG
//#ifdef NDEBUG_DAVE
	char answer = 'y';
	do {
		myGame.play();
		cout << "Do you want to play again (y/n)? ";
		cin >> answer;
	} while(toupper(answer) == 'Y');
//#endif //NDEBUG
	return 0;
}

