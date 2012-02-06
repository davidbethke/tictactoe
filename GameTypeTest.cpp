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