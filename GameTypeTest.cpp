#include "StdAfx.h"
#include "GameTypeTest.h"


GameTypeTest::GameTypeTest(void)
{
}


GameTypeTest::~GameTypeTest(void)
{
}
TEST_F(GameTypeTest,swapPlayerIndex)
{
	int current=0, next=1;
	swapPlayerIndex(current,next);
	EXPECT_EQ(1,current)<<"Current not swapped";
	EXPECT_EQ(0,next)<<"Next not swapped";
}
TEST_F(GameTypeTest,setPlayerNamesGP)
{
	int current=gP.currentPlayerNumber=0;
	int next=gP.nextPlayerNumber=1;
	swapPlayerIndex(current,next);
	EXPECT_EQ(1,current)<<"Current not swapped";
	EXPECT_EQ(0,next)<<"Next not swapped";
}
TEST_F(GameTypeTest,resultsInitialized)
{
	
	EXPECT_EQ(0,gP.results->numberMarks);
	EXPECT_FALSE(gP.results->win);
	EXPECT_EQ(Direction::NONE,gP.results->winDir);
	EXPECT_EQ(Mark::BLANK,gP.results->winMark);
	EXPECT_EQ(0,gP.results->winPlayer);
	EXPECT_EQ(0,gP.results->winPos.col);
	EXPECT_EQ(0,gP.results->winPos.row);
}
TEST_F(GameTypeTest,resultsReset)
{
	// set to some non initial vals
	gP.results->numberMarks=12;
	gP.results->win=true;
	gP.results->winDir=Direction::DIAG1;
	gP.results->winMark=Mark::EX;
	gP.results->winPlayer=1;
	gP.results->winPos=Position(2,2);

	// reset results
	gP.results->reset();
	//test
		
	EXPECT_EQ(0,gP.results->numberMarks);
	EXPECT_FALSE(gP.results->win);
	EXPECT_EQ(Direction::NONE,gP.results->winDir);
	EXPECT_EQ(Mark::BLANK,gP.results->winMark);
	EXPECT_EQ(0,gP.results->winPlayer);
	EXPECT_EQ(0,gP.results->winPos.col);
	EXPECT_EQ(0,gP.results->winPos.row);
}