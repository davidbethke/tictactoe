#include "StdAfx.h"
#include "GameParametersTest.h"


GameParametersTest::GameParametersTest(void):gP()
{
}


GameParametersTest::~GameParametersTest(void)
{
}

TEST_F(GameParametersTest,testInitVals)
{
	EXPECT_EQ(3,gP.NUMROWS);
	EXPECT_EQ(3,gP.NUMCOLS);
	EXPECT_EQ(3,gP.INAROWTOWIN);
	EXPECT_EQ(2,gP.NUMPLAYERS);
	EXPECT_EQ(0,gP.currentPlayerNumber);
	EXPECT_EQ(1,gP.nextPlayerNumber);
	EXPECT_EQ(0,gP.NUMBEROFPLAYS);
	EXPECT_EQ(0,gP.NUMBEROFOWINS);
	EXPECT_EQ(0,gP.NUMBEROFXWINS);
	EXPECT_EQ(0,gP.NUMBEROFWINS);
	EXPECT_EQ("Computer",gP.players[gP.currentPlayerNumber]->getName());
	EXPECT_EQ("Computer",gP.players[gP.nextPlayerNumber]->getName());
	EXPECT_EQ(0,gP.results->numberMarks);
		
}

