#ifndef GAMETYPE_H
#define GAMETYPE_H
#include "GameParameters.h"
#include "GameTypeHelper.h"

class GameBoard;	//forward declaration
class GameType		//forward declaration
{
public:
	
	GameType(GameParameters& gP=GameParameters()); //default GameParameters if none specified
	~GameType(void);
	void play(void);
private:
	GameParameters &gameParams;
	GameBoard *theBoard;
};

#endif //GAMETYPE_H