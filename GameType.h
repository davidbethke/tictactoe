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
	GameParameters &gameParams; // can I declare a reference here, pointer instead maybe, let's me forward declare above
	GameBoard *theBoard;
	void displayGameResults() const;
	void displayGameStats() const;
};

#endif //GAMETYPE_H