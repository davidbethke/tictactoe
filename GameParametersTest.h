#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameParameters.h"
#include "Player.h"
#include "GameResults.h"
class GameParametersTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
	GameParameters gP;
public:
	GameParametersTest(void);
	~GameParametersTest(void);
};

