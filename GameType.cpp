#include "StdAfx.h"
//#include "GameParameters.h"
#include "GameBoard.h"
#include "GameType.h"
#include <iostream>
#include "Player.h"
using namespace std;

GameType::GameType(GameParameters&  gP):gameParams(gP)
{
	theBoard= new GameBoard(gameParams);
}
GameType::~GameType(void)
{
	delete theBoard;
}
void GameType::play()
{
	
	if(!gameParams.replay)	// set player names and marks, the first time thru
	{
		gameParams.replay=true;
		setPlayerNames(gameParams.players);
		setPlayerOrder(gameParams.currentPlayerNumber,gameParams.nextPlayerNumber);
	}
	
	theBoard->clearBoard();
	theBoard->displayBoard("Initial Board");
	
	while(!theBoard->checkFull())
	{
		
		cout << "Player Number:"<<gameParams.currentPlayerNumber<< " Name:"<< gameParams.players[gameParams.currentPlayerNumber]->getName()<<" Move"<<endl;
		if(gameParams.players[gameParams.currentPlayerNumber]->move(gameParams.NUMROWS,gameParams.NUMCOLS,theBoard)) //true if valid mmove
		{
			
			theBoard->displayBoard("Board");
						
			if(theBoard->checkAllGeneric()) // various funcs for this, true if winner
			{
				gameParams.NUMBEROFPLAYS++;
				gameParams.NUMBEROFWINS++;
				if(gameParams.results->winMark == Mark::EX)
					gameParams.NUMBEROFXWINS++;
				else
					gameParams.NUMBEROFOWINS++;
				cout << "Winner!"<<endl;
				displayGameResults(gameParams);
				displayGameStats(gameParams);
				theBoard->displayBoard("Final Board");
				return; //winner
			}
			if(theBoard->checkFull()) // true if board is full
			{
				gameParams.NUMBEROFPLAYS++;
				cout << "Game Over,FULL, No Winner, Cats Game"<<endl;
				displayGameResults(gameParams);
				displayGameStats(gameParams);
				theBoard->displayBoard("Final Board");
				return;// no winner
			}
			
			swapPlayerIndex(gameParams.currentPlayerNumber,gameParams.nextPlayerNumber);
			
		}
		else
		{
			cout << "Invalid move"<<endl;
			cout << "Try Again"<<endl;
		}
	}
}



	



