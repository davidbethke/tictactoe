#include "StdAfx.h"
#include "GameType.h"
#include <iostream>
using namespace std;
/*
GameType::GameType(int n,int r,int c,int w):NUMBEROFPLAYERS(n),NUMOFROWS(r),NUMOFCOLS(c),INAROWTOWIN(w),NUMBEROFPLAYS(0)
{
	players = new Player *[NUMBEROFPLAYERS];
	for(int i=0; i<NUMBEROFPLAYERS;++i)
		players[i]= new Player;
	theBoard= new GameBoard(NUMOFROWS,NUMOFCOLS,INAROWTOWIN,4);
	 
}
*/
GameType::GameType(GameParameters&  gP):gameParams(gP)
{
	//kluge, until I transition to only GameParameters constructor
	players = new Player *[gameParams.NUMPLAYERS];
	for(int i=0; i<gameParams.NUMPLAYERS;++i)
		players[i]= new Player;
	theBoard= new GameBoard(gameParams);
	
}
/*
GameType::GameType():NUMBEROFPLAYERS(2),NUMOFROWS(3),NUMOFCOLS(3),INAROWTOWIN(3),NUMBEROFPLAYS(0)
{
	players = new Player *[NUMBEROFPLAYERS];
	for(int i=0; i<NUMBEROFPLAYERS;++i)
		players[i]= new Player;
	theBoard= new GameBoard;
	 NUMBEROFWINS=0;
	 NUMBEROFXWINS=0;
	 NUMBEROFOWINS=0;
}
*/



GameType::~GameType(void)
{
	for(int i=0;i<gameParams.NUMPLAYERS;++i)
		delete players[i];
	delete[] players;
}
bool GameType::play()
{
	// set player names and marks
	players[0]->setMark(Mark::OH);
	players[1]->setMark(Mark::EX);
	Mark::Values winningValue;
	bool firstRun=true;
	int currentPlayerNumber=0, nextPlayerNumber=1; //"normal" order
	// players alternate
	
	theBoard->clearBoard();
	cout << "Initial Board"<<endl;
	theBoard->displayBoard();
	
	while(!theBoard->checkFull())
	{
		
		cout << "Player Number:"<<currentPlayerNumber<< " Move"<<endl;
		if(players[currentPlayerNumber]->move(gameParams.NUMROWS,gameParams.NUMCOLS,theBoard))
		{
			
			cout << "Board"<<endl;
			cout <<"------"<<endl;
			theBoard->displayBoard();
					
			
			if(theBoard->checkAllGeneric(winningValue)) // various algorithms for this 
			{
				gameParams.NUMBEROFPLAYS++;
				gameParams.NUMBEROFOWINS++;
				cout << "Total Marks:"<< theBoard->getMarks()<<endl;
				cout << "Player:"<<players[currentPlayerNumber]->getName()<<endl;
				cout << "value is:"<<markValues[winningValue]<<endl; // take enum, translate to string
				cout << "In a row to win:"<< gameParams.INAROWTOWIN<<endl;
				if(winningValue == Mark::EX)
					gameParams.NUMBEROFXWINS++;
				else
					gameParams.NUMBEROFOWINS++;

				cout << "Game Stats: Plays:"<<gameParams.NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*gameParams.NUMBEROFWINS/gameParams.NUMBEROFPLAYS)*100.0<<"%"<<endl;
				cout << "X Win Percent:"<<(1.0*gameParams.NUMBEROFXWINS/gameParams.NUMBEROFPLAYS)*100.0<<" % O Win Percent:"<<(1.0*gameParams.NUMBEROFOWINS/gameParams.NUMBEROFPLAYS)*100.0<<" %"<<endl;
				cout << "Final Board"<<endl;
				theBoard->displayBoard();
				return true; //winner
			}
			if(theBoard->checkFull())
			{
				gameParams.NUMBEROFPLAYS++;
				cout << "Game Over,FULL"<<endl;
				cout << "Total Marks:"<< theBoard->getMarks()<<endl;
				cout << "In a row to win:"<< gameParams.INAROWTOWIN<<endl;
				cout << "Game Stats: Plays:"<<gameParams.NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*gameParams.NUMBEROFWINS/gameParams.NUMBEROFPLAYS)*100.0<<"%"<<endl;
				cout << "X Win Percent:"<<(1.0*gameParams.NUMBEROFXWINS/gameParams.NUMBEROFPLAYS)*100.0<<" % O Win Percent:"<<(1.0*gameParams.NUMBEROFOWINS/gameParams.NUMBEROFPLAYS)*100.0<<" %"<<endl;
				cout << "Final Board"<<endl;
				theBoard->displayBoard();
				
				return false; // no winner
				
			}
			// next player, repeat til board full, or checkAll for a win
			// swap current  players
			swapPlayerIndex(currentPlayerNumber,nextPlayerNumber);
			

		}
		else
		{
			cout << "Invalid move"<<endl;
			cout << "Try Again"<<endl;
			// no swapPlayerIndex here, let the idiot try again!
		}
	}

	/*
	cout << "Total Marks:"<< theBoard->getMarks()<<endl;
	cout << "Final Board"<<endl;
	theBoard->displayBoard();
	*/
	return theBoard->checkAllGeneric(winningValue);
	
	

}
void GameType::swapPlayerIndex(int & a, int & b)
{
	int temp=a;
	a=b;
	b=temp;

}
void GameType::getPlayerNames(Player ** p) 
{
	std::string name0, name1;
	// player 0
	std::cout<<"Enter Player 0 Name"<<std::endl;
	std::cout << p[0]->getName()<<endl;
	cin >> name0;
	if(!name0.empty())
		p[0]->setName(name0);
	std::cout<<"Enter Player 1 Name"<<std::endl;
	std::cout << p[1]->getName()<<endl;
	cin >> name0;
	if(!name1.empty())
		p[1]->setName(name0);
	
}
void GameType::getPlayerOrder(int& first, int& second)
{
	int selectReversed;
	std::cout<<"Enter First Player, 0 or 1"<<std::endl;
	cin >> selectReversed;
	if(selectReversed)
		swapPlayerIndex(first,second);
}

	



