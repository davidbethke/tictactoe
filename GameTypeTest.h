#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameType.h"
#include "GameParameters.h"
class GameTypeTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
	GameType gT;
	GameParameters gP;

public:
	GameTypeTest(void);
	~GameTypeTest(void);
};

