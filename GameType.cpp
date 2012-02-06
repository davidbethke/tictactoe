#include "StdAfx.h"
#include "GameType.h"
#include <iostream>
#include <iomanip>
using namespace std;

GameType::GameType(GameParameters&  gP):gameParams(gP)
{
	
	players = new Player *[gameParams.NUMPLAYERS];
	for(int i=0; i<gameParams.NUMPLAYERS;++i)
		players[i]= new Player;
	theBoard= new GameBoard(gameParams);
	
}
GameType::~GameType(void)
{
	for(int i=0;i<gameParams.NUMPLAYERS;++i)
		delete players[i];
	delete[] players;
}
void GameType::play()
{
	// set player names and marks
	players[0]->setMark(Mark::OH);
	players[1]->setMark(Mark::EX);
	
	theBoard->clearBoard();
	//cout << "Initial Board"<<endl;
	theBoard->displayBoard("Initial Board");
	
	while(!theBoard->checkFull())
	{
		
		cout << "Player Number:"<<gameParams.currentPlayerNumber<< " Move"<<endl;
		if(players[gameParams.currentPlayerNumber]->move(gameParams.NUMROWS,gameParams.NUMCOLS,theBoard))
		{
			
			//cout << "Board"<<endl;
			//cout <<"------"<<endl;
			theBoard->displayBoard("Board");
					
			
			if(theBoard->checkAllGeneric()) // various algorithms for this 
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
			if(theBoard->checkFull())
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
void GameType::displayGameResults() const
{
	cout << "Total Marks Played:"<< gameParams.results->numberMarks<<endl;
	cout << "Last Player:"<<players[gameParams.currentPlayerNumber]->getName()<<endl;
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
	theBoard->displayBoard();
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


	



