#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameType.h"
#include "GameParameters.h"
class GameType;
struct GameParameters;
class GameTypeTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		GameParameters gP=GameParameters();
		GameType gT=GameType(gP);
	}
	virtual void TearDown()
	{
	}
	GameParameters  gP;
	GameType  gT;
	

public:
	GameTypeTest(void);
	~GameTypeTest(void);
};

