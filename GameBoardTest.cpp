#include "StdAfx.h"
#include "GameBoardTest.h"
bool GameBoardTest::fillBoard(const int numRows, const int numCols,const Mark::Values & mark )
{
	bool result=false;
	for (int i=0; i<numRows;++i)
	{
		for (int k=0;k<numCols;++k)
		{
			result =gb.markBoard(i,k,mark);
		}
	}
	return result;
}
bool GameBoardTest::markWinner(const Direction& dir,const int& number, int row, int col,const Mark::Values& mark)
{
	bool result=false;
	int rowAdd=0, colAdd=0;
	switch (dir)
	{
		case ACROSS:
			rowAdd=0;
			colAdd=1;
			break;
		case DOWN:
			rowAdd=1;
			colAdd=0;
			break;
		case DIAG1:
			rowAdd=1;
			colAdd=1;
			break;
		case DIAG2:
			rowAdd=-1;
			colAdd=1;
			break;
		default:
			break;
	}

	for (int i=0; i<number;++i)
	{
		
		result=(gb.markBoard(row,col,mark));
		row+=rowAdd;
		col+=colAdd;

	}
	return result;

}
/*
No access to private data members
Tried to friend GameBoard.h but didnt work, try later
TEST_F(GameBoardTest,initialGameParams)
{
	EXPECT_EQ(2,gb.gameParams.NUMPLAYERS);
	EXPECT_EQ(3,gb.gameParams.NUMROWS);
	EXPECT_EQ(3,gb.gameParams.NUMCOLS);
	EXPECT_EQ(3,gb.gameParams.INAROWTOWIN);
	EXPECT_EQ(0,gb.gameParams.NUMBEROFPLAYS);
	EXPECT_EQ(0,gb.gameParams.NUMBEROFWINS);
	EXPECT_EQ(0,gb.gameParams.NUMBEROFXWINS);
	EXPECT_EQ(0,gb.gameParams.NUMBEROFOWINS);
}
*/
TEST_F(GameBoardTest,notFull)
{
	EXPECT_FALSE(gb.checkFull());
}
TEST_F(GameBoardTest,markBoard)
{
	EXPECT_TRUE(gb.markBoard(0,0,Mark::EX));
	EXPECT_TRUE(gb.markBoard(1,0,Mark::OH));
	EXPECT_TRUE(gb.markBoard(2,0,Mark::W));
	EXPECT_FALSE(gb.markBoard(1,0,Mark::BLANK));
}
TEST_F(GameBoardTest,checkFullBlank)
{
	bool result=false;
	result=GameBoardTest::fillBoard(3,3,Mark::BLANK);
	EXPECT_FALSE(result)<< "filled the board w/ BLANKS, stop test";
	EXPECT_FALSE(gb.checkFull())<< "Failed CheckFull";
}
TEST_F(GameBoardTest,checkFullEx)
{
	bool result=false;
	result=GameBoardTest::fillBoard(3,3,Mark::OH);
	EXPECT_TRUE(result)<< "Didn't fill the board, stop test";
	EXPECT_TRUE(gb.checkFull())<< "Failed CheckFull";

}
TEST_F(GameBoardTest,checkFullOh)
{
	bool result=false;
	result=GameBoardTest::fillBoard(3,3,Mark::EX);
	EXPECT_TRUE(result)<< "Didn't fill the board, stop test";
	EXPECT_TRUE(gb.checkFull())<< "Failed CheckFull";
}
TEST_F(GameBoardTest,checkFullW)
{
	bool result=false;
	result=GameBoardTest::fillBoard(3,3,Mark::W);
	EXPECT_TRUE(result)<< "Didn't fill the board, stop test";
	EXPECT_TRUE(gb.checkFull())<< "Failed CheckFull";
}
TEST_F(GameBoardTest,markWinnerAcrossOManual)
{
	
	EXPECT_TRUE(gb.markBoard(0,0,Mark::OH))<<"Failed Mark O, 0,0";
	EXPECT_TRUE(gb.markBoard(0,1,Mark::OH))<<"Failed Mark O, 0,1";
	EXPECT_TRUE(gb.markBoard(0,2,Mark::OH))<<"Failed Mark O, 0,2";
	EXPECT_TRUE(gb.checkAllGeneric())<< "Failed to Find Winner";

}
TEST_F(GameBoardTest,markWinnerAcrossO)
{
	bool result=false;
	result=markWinner(Direction::ACROSS,3,0,0,Mark::OH);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}

TEST_F(GameBoardTest,markWinnerAcrossX)
{
	bool result=false;
	result=markWinner(Direction::ACROSS,3,0,0,Mark::EX);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}
TEST_F(GameBoardTest,markWinnerAcrossW)
{
	bool result=false;
	result=markWinner(Direction::ACROSS,3,0,0,Mark::W);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_FALSE(gb.checkAllGeneric())<< "Can't win w/ a W"

}
TEST_F(GameBoardTest,markWinnerDownO)
{
	bool result=false;
	result=markWinner(Direction::DOWN,3,0,0,Mark::OH);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}

TEST_F(GameBoardTest,markWinnerDownX)
{
	bool result=false;
	result=markWinner(Direction::DOWN,3,0,0,Mark::EX);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}
TEST_F(GameBoardTest,markWinnerDownW)
{
	bool result=false;
	result=markWinner(Direction::DOWN,3,0,0,Mark::W);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_FALSE(gb.checkAllGeneric())<< "Can't win w/ a W"

}
TEST_F(GameBoardTest,markWinnerDiag1O)
{
	bool result=false;
	result=markWinner(Direction::DIAG1,3,0,0,Mark::OH);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}

TEST_F(GameBoardTest,markWinnerDiag1X)
{
	bool result=false;
	result=markWinner(Direction::DIAG1,3,0,0,Mark::EX);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}
TEST_F(GameBoardTest,markWinnerDiag1W)
{
	bool result=false;
	result=markWinner(Direction::DIAG2,3,0,0,Mark::W);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_FALSE(gb.checkAllGeneric())<< "Can't win w/ a W"

}
TEST_F(GameBoardTest,markWinnerDiag2O)
{
	bool result=false;
	result=markWinner(Direction::DIAG2,3,2,0,Mark::OH);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}

TEST_F(GameBoardTest,markWinnerDiag2X)
{
	bool result=false;
	result=markWinner(Direction::DIAG2,3,2,0,Mark::EX);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_TRUE(gb.checkAllGeneric());

}
TEST_F(GameBoardTest,markWinnerDiag2W)
{
	bool result=false;
	result=markWinner(Direction::DIAG2,3,2,0,Mark::W);
	EXPECT_TRUE(result)<<"Didn't Mark the Board, correctly";
	EXPECT_FALSE(gb.checkAllGeneric())<< "Can't win w/ a W";

}




