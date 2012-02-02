
#include "Player.h"
#ifndef GAMETYPE
#define GAMETYPE

class GameType
{
public:
	GameType(int n=2,int r=3,int c=3,int w=3);
	//GameType();
	~GameType(void);
	bool clearBoard(void);
	bool play(void);
private:
	const int NUMBEROFPLAYERS;
	int NUMBEROFPLAYS;
	int NUMBEROFWINS;
	int NUMBEROFXWINS;
	int NUMBEROFOWINS;
	const int NUMOFROWS;
	const int NUMOFCOLS;
	const int INAROWTOWIN;
	GameBoard *theBoard;
	Player **players;
	void swapPlayerIndex(int &,int &);
	void getPlayerNames(Player **);
	void getPlayerOrder(int &, int&);

};

#endif