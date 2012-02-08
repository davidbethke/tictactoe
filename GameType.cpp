#include "StdAfx.h"
#include "GameParameters.h"
#include "GameBoard.h"
#include "GameType.h"
#include <iostream>
#include <iomanip>

#include "Player.h"
using namespace std;

GameType::GameType(GameParameters&  gP=GameParameters()):gameParams(gP)
{
	/*
	gameParams.players = new Player *[gameParams.NUMPLAYERS];
	for(int i=0; i<gameParams.NUMPLAYERS;++i)
		gameParams.players[i]= new Player;
	*/
	//theBoard= new GameBoard(gameParams);
	
	
}
GameType::~GameType(void)
{
	for(int i=0;i<gameParams.NUMPLAYERS;++i)
		delete gameParams.players[i];
	delete[] gameParams.players;
}
void GameType::play()
{
	// set player names and marks
	setPlayerNames(gameParams.players);
	setPlayerOrder(gameParams.currentPlayerNumber,gameParams.nextPlayerNumber);
	//gameParams.players[0]->setMark(Mark::OH);
	//gameParams.players[1]->setMark(Mark::EX);
	
	gameParams.theBoard->clearBoard();
	//cout << "Initial Board"<<endl;
	gameParams.theBoard->displayBoard("Initial Board");
	
	while(!gameParams.theBoard->checkFull())
	{
		
		cout << "Player Number:"<<gameParams.currentPlayerNumber<< " Name:"<< gameParams.players[gameParams.currentPlayerNumber]->getName()<<" Move"<<endl;
		if(gameParams.players[gameParams.currentPlayerNumber]->move(gameParams.NUMROWS,gameParams.NUMCOLS,gameParams.theBoard))
		{
			
			//cout << "Board"<<endl;
			//cout <<"------"<<endl;
			gameParams.theBoard->displayBoard("Board");
					
			
			if(gameParams.theBoard->checkAllGeneric()) // various algorithms for this, true if winner
			{
				gameParams.NUMBEROFPLAYS++;
				gameParams.NUMBEROFWINS++;
				
				if(gameParams.results->winMark == Mark::EX)
					gameParams.NUMBEROFXWINS++;
				else
					gameParams.NUMBEROFOWINS++;
				cout << "Winner!"<<endl;
				displayGameResults();
				displayGameStats();
				return; //winner
			}
			if(gameParams.theBoard->checkFull()) // true if board is full
			{
				gameParams.NUMBEROFPLAYS++;
				cout << "Game Over,FULL, No Winner, Cats Game"<<endl;
				displayGameResults();
				displayGameStats();
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
	return;
	
}
/*
void GameType::swapPlayerIndex(int & a, int & b)
{
	int temp=a;
	a=b;
	b=temp;
}
void GameType::setPlayerNames(Player ** p) 
{
	string name0, name1;
	// player 0
	cout<<"Enter Player 0 Name"<<"default ("<<p[0]->getName()<<endl;
	cin >> name0;
	if(!name0.empty())
		p[0]->setName(name0);
	cout<<"Enter Player 1 Name"<<"default ("<<p[1]->getName()<<endl;
	cin >> name0;
	if(!name1.empty())
		p[1]->setName(name0);
	
}
void GameType::setPlayerOrder(int& first, int& second)
{
	char answer='n';
	cout<<"Swap Player Order y/n"<<endl;
	cin >> answer;
	if(answer=='y')
		swapPlayerIndex(first,second);
}
*/
void GameType::displayGameResults() const
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
void GameType::displayGameStats() const
{
	cout << "Game Stats: Plays:"<<gameParams.NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*gameParams.NUMBEROFWINS/gameParams.NUMBEROFPLAYS)*100.0<<"%"<<endl;
	cout << "X Win Percent:"<<setprecision(4)<<(1.0*gameParams.NUMBEROFXWINS/gameParams.NUMBEROFPLAYS)*100.0<<" % O Win Percent:"<<(1.0*gameParams.NUMBEROFOWINS/gameParams.NUMBEROFPLAYS)*100.0<<" %"<<endl;
	cout << "Final Board"<<endl;
	cout << "-----------"<<endl;
	gameParams.theBoard->displayBoard();
}
void swapPlayerIndex(int & a, int & b)
{
	int temp=a;
	a=b;
	b=temp;
}
void setPlayerOrder(int& first, int& second)
{
	char answer='n';
	cout<<"Swap Player Order y/n"<<endl;
	cin >> answer;
	if(answer=='y')
		swapPlayerIndex(first,second);
}
void setPlayerNames(Player ** p) 
{
	string name0="", name1="";
	// player 0
	//cout<<"Enter Player 0 Name"<<" default ( "<<p[0]->getName()<<")"<<endl;
	cout <<"Enter Player 0 Name, enter 0 for Computer"<<endl;
	cin >> name0;
	//cout <<endl;
	//cout <<"Name:"<<name0<<endl;
	if(name0 != "0")
		p[0]->setName(name0);
	//cout<<"Enter Player 1 Name"<<"default ( "<<p[1]->getName()<<")"<<endl;
	cout <<"Enter Player 1 Name, enter 0 for Computer"<<endl;
	cin >> name1;
	if(name1 !="0")
		p[1]->setName(name1);
	//setMarks
	p[0]->setMark(Mark::OH);
	p[1]->setMark(Mark::EX);
	
}


	



