#include "StdAfx.h"
#include "GameParameters.h"


GameParameters::GameParameters(int r,int c, int rw,int np):NUMROWS(r),NUMCOLS(c),INAROWTOWIN(rw),NUMPLAYERS(np),NUMBEROFPLAYS(0)
	,NUMBEROFWINS(0),NUMBEROFOWINS(0),NUMBEROFXWINS(0)
{
}


GameParameters::~GameParameters(void)
{
}
