//#pragma once
#ifdef _DEBUG
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "GameSquare.h"
class GameSquareTest :
	public testing::Test
{
protected:
	virtual void SetUp()
	{
		gsO.setValue(Mark::OH);
		gsX.setValue(Mark::EX);
		gsW.setValue(Mark::W);
		//gsB default initialized to Blank
		
	}
	virtual void TearDown()
	{
	}
	GameSquare gsO,gsX,gsB,gsW;

};
#endif


