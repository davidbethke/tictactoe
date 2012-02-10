//#pragma once
#ifdef _DEBUG
#define GAMEBOARDTEST_H
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameBoard.h"
#include "GameParameters.h"
class GameBoardTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		//GameParameters gP= GameParameters();
		//GameBoard gB=GameBoard();
	
	}
	virtual void TearDown()
	{
	}
	bool fillBoard(const int numRows, const int numCols,const Mark & mark);
	bool markWinner(const Direction&,const int&, int, int,const Mark&);
	GameParameters gP;
	GameBoard gb;
	
public:
	GameBoardTest();
	
};
#endif

