#ifndef GAMERESULTS_H
#define GAMERESULTS_H
#include "Mark.h"
#include "Position.h"
#include "Direction.h"
struct GameResults
{
	GameResults(void);
	~GameResults(void);
	Mark::Values winMark;
	Position	 winPos;
	Direction winDir;
	int	winPlayer;
	bool win;
	int numberMarks;
	void reset();
};
#endif
