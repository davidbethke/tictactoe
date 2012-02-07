#ifndef GAMETYPE_H
#define GAMETYPE_H
//#include "Player.h"
//class GameBoard; // forward declaration
//#include "GameBoard.h"
struct GameParameters;
class Player;
class GameType
{
public:
	
	GameType(GameParameters& gP); //default GameParameters if none specified
	~GameType(void);
	void play(void);
private:
	GameParameters &gameParams; // can I declare a reference here, pointer instead maybe
	//GameBoard *theBoard;
	//Player **players; // move to gameParams
	//void swapPlayerIndex(int &,int &);
	//void setPlayerNames(Player **); 
	//void setPlayerOrder(int &, int&);
	void displayGameResults() const;
	void displayGameStats() const;
	
};
//helper
void swapPlayerIndex(int &,int &);
void setPlayerOrder(int &, int&);
void setPlayerNames(Player **);
#endif