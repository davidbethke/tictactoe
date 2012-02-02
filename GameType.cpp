#include "StdAfx.h"
#include "GameType.h"
#include <iostream>
using namespace std;

GameType::GameType(int n=2,int r=3,int c=3,int w=3):NUMBEROFPLAYERS(n),NUMOFROWS(r),NUMOFCOLS(c),INAROWTOWIN(w),NUMBEROFPLAYS(0)
{
	players = new Player *[NUMBEROFPLAYERS];
	for(int i=0; i<NUMBEROFPLAYERS;++i)
		players[i]= new Player;
	theBoard= new GameBoard(NUMOFROWS,NUMOFCOLS,INAROWTOWIN,4);
	 NUMBEROFWINS=0;
	 NUMBEROFXWINS=0;
	 NUMBEROFOWINS=0;

}

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



GameType::~GameType(void)
{
	for(int i=0;i<NUMBEROFPLAYERS;++i)
		delete players[i];
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
	int testValue=0;
	while(!theBoard->checkFull())
	{
		//testValue++;
		cout << "Player Number:"<<currentPlayerNumber<< " Move"<<endl;
		if(players[currentPlayerNumber]->move(NUMOFROWS,NUMOFCOLS,theBoard))
		{
			//Display Board after player move
			//test for all blanks
			//theBoard->clearBoard();
			/*
			if(!theBoard->checkBlank()&&firstRun)
			{
				cout<< "Not All Blank"<<endl;
				firstRun=false;
			}
			else
			*/
			
			cout << "Board"<<endl;
			cout <<"------"<<endl;
			theBoard->displayBoard();
					
			
			if(theBoard->checkAllGeneric(winningValue)) // various algorithms for this 
			{
				NUMBEROFPLAYS++;
				NUMBEROFWINS++;
				cout << "Total Marks:"<< theBoard->getMarks()<<endl;
				cout << "Player:"<<players[currentPlayerNumber]->getName()<<endl;
				cout << "value is:"<<markValues[winningValue]<<endl; // take enum, translate to string
				cout << "In a row to win:"<< INAROWTOWIN<<endl;
				if(winningValue == Mark::EX)
					NUMBEROFXWINS++;
				else
					NUMBEROFOWINS++;

				cout << "Game Stats: Plays:"<<NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*NUMBEROFWINS/NUMBEROFPLAYS)*100.0<<"%"<<endl;
				cout << "X Win Percent:"<<(1.0*NUMBEROFXWINS/NUMBEROFPLAYS)*100.0<<" % O Win Percent:"<<(1.0*NUMBEROFOWINS/NUMBEROFPLAYS)*100.0<<" %"<<endl;
				cout << "Final Board"<<endl;
				theBoard->displayBoard();
				return true; //winner
			}
			if(theBoard->checkFull())
			{
				NUMBEROFPLAYS++;
				cout << "Game Over,FULL"<<endl;
				cout << "Total Marks:"<< theBoard->getMarks()<<endl;
				cout << "In a row to win:"<< INAROWTOWIN<<endl;
				cout << "Game Stats: Plays:"<<NUMBEROFPLAYS<<" WIN PERCENT:"<<(1.0*NUMBEROFWINS/NUMBEROFPLAYS)*100.0<<"%"<<endl;
				cout << "X Win Percent:"<<(1.0*NUMBEROFXWINS/NUMBEROFPLAYS)*100.0<<" % O Win Percent:"<<(1.0*NUMBEROFOWINS/NUMBEROFPLAYS)*100.0<<" %"<<endl;
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

	



