#include "StdAfx.h"
#include "GameParameters.h"


GameParameters::GameParameters(int r,int c, int rw):NUMROWS(r),NUMCOLS(c),INAROWTOWIN(rw),NUMBEROFPLAYS(0)
	,NUMBEROFWINS(0),NUMBEROFOWINS(0),NUMBEROFXWINS(0),currentPlayerNumber(0),nextPlayerNumber(1)
{
	results=new GameResults;
}
GameParameters::~GameParameters(void)
{
}
