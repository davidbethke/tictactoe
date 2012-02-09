#include "StdAfx.h"
#include "GameParameters.h"
#include "Player.h"
#include "GameResults.h"
#include "GameBoard.h"
GameParameters::GameParameters(int r,int c, int rw):NUMROWS(r),NUMCOLS(c),INAROWTOWIN(rw),NUMBEROFPLAYS(0),
				NUMBEROFWINS(0),NUMBEROFOWINS(0),NUMBEROFXWINS(0),currentPlayerNumber(0),nextPlayerNumber(1)
{
	
	players = new Player *[NUMPLAYERS];	//init players
	for(int i=0; i<NUMPLAYERS;++i)
		players[i]= new Player;
	results=new GameResults;			//init results
	
}
GameParameters::~GameParameters(void)
{
	
	for(int i=0; i<NUMPLAYERS;++i)
		delete players[i];
	
	delete[] players;
	delete results;
}
