#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameType.h"
#include "GameParameters.h"
#include "Player.h"
class GameType;
struct GameParameters;
class GameTypeTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		GameParameters gP=GameParameters();
		gP.players = new Player*[gP.NUMPLAYERS];
		for(int i=0; i<gP.NUMPLAYERS;++i)
			gP.players[i]=new Player;
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

