#include "StdAfx.h"
#include "GameParametersHelper.h"
#include "GameParameters.h"
#include "GameResults.h"
#include "Direction.h"
#include "Mark.h"
#include "Player.h"
#include <iomanip>

#include <iostream>
using namespace std;
void displayGameResults(GameParameters& gameParams) 
{
	cout << "Total Marks Played:"<< gameParams.results->numberMarks<<endl;
	cout << "Last Player:"<<gameParams.players[gameParams.currentPlayerNumber]->getName()<<endl;
	if(gameParams.results->win)
	{
		cout << "Winning Mark is:"<<markValues[gameParams.results->winMark]<<endl; // take enum, translate to string
		cout << "Winning Direction is:"<<DirString[gameParams.results->winDir]<<endl;
	}
	cout << "In a row to win:"<< gameParams.INAROWTOWIN<<endl;
}
void displayGameStats(GameParameters& gameParams) 
{
	cout << "Game Stats: Plays:"<<gameParams.NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*gameParams.NUMBEROFWINS/gameParams.NUMBEROFPLAYS)*100.0<<"%"<<endl;
	cout << "X Win Percent:"<<setprecision(4)<<(1.0*gameParams.NUMBEROFXWINS/gameParams.NUMBEROFPLAYS)*100.0<<" % O Win Percent:"
							<<(1.0*gameParams.NUMBEROFOWINS/gameParams.NUMBEROFPLAYS)*100.0<<" %"<<endl;
	
	
}