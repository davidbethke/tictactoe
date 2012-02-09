#ifndef GAMEPARAMETERS_H
#define	GAMEPARAMETERS_H	
#include "GameParametersHelper.h"
class Player; // forward declaration
struct GameResults;// forward declaration

struct GameParameters
{
	GameParameters(int r=3,int c=3, int rw=3); //default to tic tac toe
	~GameParameters(void);
	const int NUMROWS;
	const int NUMCOLS;
	const int INAROWTOWIN;
	static const int NUMPLAYERS=2;
	Player **players;
	int NUMBEROFPLAYS;
	int NUMBEROFWINS;
	int NUMBEROFXWINS;
	int NUMBEROFOWINS;
	int currentPlayerNumber;
	int nextPlayerNumber;
	GameResults *results;
};

#endif
