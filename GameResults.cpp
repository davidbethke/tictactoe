#include "StdAfx.h"
#include "GameResults.h"


GameResults::GameResults(void):winMark(Mark::BLANK),winPos(),winDir(Direction::NONE),winPlayer(),win(false),numberMarks(0)
{
}


GameResults::~GameResults(void)
{
}
void GameResults::reset()
{
	winMark=Mark::BLANK;
	winPos.reset();
	winDir=Direction::NONE;
	winPlayer=0;
	win=false;
	numberMarks=0;
}