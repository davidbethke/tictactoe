#ifndef GAMETYPE_H
#define GAMETYPE_H
#include "Player.h"
#include "GameParameters.h"
class GameType
{
public:
	/*GameType(int n=2,int r=3,int c=3,int w=3);*/
	GameType(GameParameters& gP);
	//GameType();
	~GameType(void);
	//void clearBoard(void);
	void play(void);
private:
	GameParameters gameParams;
	//const int NUMBEROFPLAYERS;
	//int NUMBEROFPLAYS;
	//int NUMBEROFWINS;
	//int NUMBEROFXWINS;
	//int NUMBEROFOWINS;
	//const int NUMOFROWS;
	//const int NUMOFCOLS;
	//const int INAROWTOWIN;
	GameBoard *theBoard;
	Player **players;
	void swapPlayerIndex(int &,int &);
	void getPlayerNames(Player **); 
	void getPlayerOrder(int &, int&);
	void displayGameResults() const;
	void displayGameStats() const;
	

};

#endif