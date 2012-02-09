#include "StdAfx.h"
#include "GameSquare.h"


GameSquare::GameSquare(void):mark(Mark::BLANK)
{
	
}
GameSquare::~GameSquare(void)
{
	
}
bool GameSquare::isBlank() const
{
	return (mark == Mark::BLANK);
}
Mark::Values GameSquare::getValue() const
{
	return mark;
}
void GameSquare::setValue(Mark::Values s)
{
	mark=s;
	//return true; // part of the check for a valid move
}
bool GameSquare::hasValue() const
{
	return ((mark == Mark::EX) || (mark == Mark::OH));
}
std::string GameSquare::getSValue() const
{
	return markValues[mark]; // char * markValues automatically cast to string
}

