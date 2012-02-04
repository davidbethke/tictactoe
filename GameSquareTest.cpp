#include "StdAfx.h"
#include "GameSquareTest.h"

TEST_F(GameSquareTest, initializedBlank)
{
	
	EXPECT_EQ(Mark::BLANK,gsB.getValue());
}
TEST_F(GameSquareTest,hasValue)
{
	EXPECT_TRUE(gsX.hasValue());
	EXPECT_TRUE(gsO.hasValue());
	EXPECT_FALSE(gsW.hasValue());
	EXPECT_FALSE(gsB.hasValue());
}
TEST_F(GameSquareTest,getValue)
{
	EXPECT_EQ(Mark::BLANK,gsB.getValue());
	EXPECT_EQ(Mark::EX,gsX.getValue());
	EXPECT_EQ(Mark::OH,gsO.getValue());
	EXPECT_EQ(Mark::W,gsW.getValue());

}
TEST_F(GameSquareTest,getSvalue)
{
	EXPECT_EQ("*",gsB.getSValue());
	EXPECT_EQ("X",gsX.getSValue());
	EXPECT_EQ("O",gsO.getSValue());
	EXPECT_EQ("W",gsW.getSValue());

}