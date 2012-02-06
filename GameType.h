#ifndef GAMETYPE_H
#define GAMETYPE_H
#include "Player.h"
#include "GameParameters.h"
class GameType
{
public:
	
	GameType(GameParameters& gP=GameParameters()); //default GameParameters if none specified
	~GameType(void);
	void play(void);
private:
	GameParameters gameParams;
	GameBoard *theBoard;
	Player **players;
	void swapPlayerIndex(int &,int &);
	void setPlayerNames(Player **); 
	void setPlayerOrder(int &, int&);
	void displayGameResults() const;
	void displayGameStats() const;
	
};
void swapPlayerIndex(int &,int &);
void setPlayerOrder(int &, int&);
void setPlayerNames(Player **);
#endif