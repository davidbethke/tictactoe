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
Mark GameSquare::getValue() const
{
	return mark;
}
void GameSquare::setValue(Mark s)
{
	mark=s;
	
}
bool GameSquare::hasValue() const
{
	return ((mark == Mark::EX) || (mark == Mark::OH));
}
std::string GameSquare::getSValue() const
{
	return markValues[mark]; // char * markValues automatically cast to string
}

