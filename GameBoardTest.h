#pragma once
#define GAMEBOARDTEST_H
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameBoard.h"
class GameBoardTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	
	}
	virtual void TearDown()
	{
	}
	bool fillBoard(const int numRows, const int numCols,const Mark::Values & mark);
	bool markWinner(const Direction&,const int&, int, int,const Mark::Values&);
	GameBoard gb;
	//GameParameters gP;
};

