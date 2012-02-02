#include "StdAfx.h"
#include "GameSquare.h"


GameSquare::GameSquare(void):mark(Mark::BLANK)
{
	
}


GameSquare::~GameSquare(void)
{
	// do nothing
}
bool GameSquare::isBlank() const
{
	//TODO figure out equality of an enum
	//return (mark == Mark.Enum.blank);
	return (mark == Mark::BLANK);
	//return false;
}
Mark::Values GameSquare::getValue() const
{
	return mark;
}
bool GameSquare::setValue(Mark::Values s)
{
	mark=s;
	return true;
}
bool GameSquare::hasValue() const
{
	return ((mark == Mark::EX) || (mark == Mark::OH));
}
std::string GameSquare::getSValue() const
{
	return markValues[mark];
}

