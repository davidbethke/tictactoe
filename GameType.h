#ifndef GAMETYPE_H
#define GAMETYPE_H
#include "GameParameters.h"
//struct GameParameters; //forward declaration
//class Player;			//forward declaration
class GameBoard;
class GameType
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

//helper
void swapPlayerIndex(int &,int &);
void setPlayerOrder(int &, int&);
void setPlayerNames(Player **);
#endif