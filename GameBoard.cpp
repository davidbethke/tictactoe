#include "StdAfx.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard(GameParameters& gP):gameParams(gP)
{
	typedef  void(*myInc)(Position &);					//define myInc as a pointer to inc Funcs
	
	gameBoard= new GameSquare *[gameParams.NUMROWS];	//init gameboard
	for (int i=0; i<gameParams.NUMROWS;++i)
		gameBoard[i]= new GameSquare[gameParams.NUMCOLS];
	
	searchFunctionArr= new myInc[NUMBEROFFUNCS];		//init function array
	searchFunctionArr[0]=acrossInc;
	searchFunctionArr[1]=downInc;
	searchFunctionArr[2]=diagInc;
	searchFunctionArr[3]=diagDec;
	
}
GameBoard::~GameBoard(void)
{
	//Clean up pointers
	for(int i=0; i< gameParams.NUMROWS;++i)
			delete[] gameBoard[i];
	delete [] gameBoard;
	/* IDE tells me a pointer to a function cannot be deleted
	for (int i=0;i<NUMBEROFFUNCS;++i)
		delete searchFunctionArr[i];
	*/
	delete[] searchFunctionArr; 
}
bool GameBoard::checkFull() const
{
	return gameParams.results->numberMarks == (gameParams.NUMROWS*gameParams.NUMCOLS);
}
void GameBoard::clearBoard()
{
	//cout << "Clearing Board .."<<endl;
	gameParams.results->reset();
	for(int i=0; i<gameParams.NUMROWS;++i)
	{
		for(int j=0; j<gameParams.NUMCOLS;++j)
		{
			gameBoard[i][j].setValue(Mark::BLANK);
		}
	}
}
bool GameBoard::markBoard(int r, int c, Mark::Values mark)
{
	if((gameBoard[r][c].hasValue())|| (mark==Mark::BLANK)) // can't mark if has value, can't mark w/ a BLANK
		return false;
	else
	{
		gameParams.results->numberMarks++;
		gameBoard[r][c].setValue(mark);
		return true; // set should be void
	}
}
bool GameBoard::checkAllGeneric() 
{
	
	for(int i=0;i<gameParams.NUMROWS;++i)
	{
		for(int j=0;j<gameParams.NUMCOLS;++j)
		{
			Position startPos(i,j);						//search this gamesquare w/ all inc functions
			for(int k=0;k<NUMBEROFFUNCS;++k)
			{
				if(searchGeneric(startPos,searchFunctionArr[k]))
				{
					gameParams.results->win=true;
					gameParams.results->winDir=static_cast<Direction>(k);
				}
			
			}
		}
	}
	
	return gameParams.results->win;
}
void GameBoard::displayBoard(string n) const
{
	cout << n<<endl;
	cout <<"----------"<<endl;
	for (int i=0; i<gameParams.NUMROWS;++i)
	{
		for(int j=0;j<gameParams.NUMCOLS;++j)
			cout<<gameBoard[i][j].getSValue()<<"|";
			cout <<endl;
		for(int k=0;k<gameParams.NUMCOLS;++k) // draw the gameboard, horiz lines
			cout <<"--";
		cout<<endl;
	}

}
bool GameBoard::searchGeneric(Position start,void(*inc)(Position&))
{
	
	bool win=false;
	int matchCount=1;
	Position winPos(start);
		
	Position first(start);					// start count position
	Position current(start);				// variable count position, if current-start >= INAROW, then a win
	inc(current);							// set current one after start to init

	while(inBounds(current))
	{
		if(gameBoard[first.row][first.col].isBlank()||gameBoard[first.row][first.col].getValue()==Mark::W) // need a value, not blank or W
		{
			inc(first);
			inc(current);
			matchCount=1;
		}
		else if(gameBoard[first.row][first.col].getValue() == gameBoard[current.row][current.col].getValue()) // match
		{
			matchCount++;
			if(matchCount==gameParams.INAROWTOWIN)
			{
				win=true;
				gameParams.results->winMark=gameBoard[first.row][first.col].getValue();
				winPos=first;
				matchCount=1;
			}
			inc(current);
					
		}
		else				// no match reset the iterators
		{
			first=current; // move fixed position 
			inc(current);  //inc current position
			matchCount=1;   // didn't match reset
		}
	}
	
	if(win)
	{
		
		gameParams.results->winPos=winPos;
			
		for(int i=0; i<gameParams.INAROWTOWIN;++i) //Mark up the board w/ W to identify the winner, up to the inARow amt
		{
			gameBoard[winPos.row][winPos.col].setValue(Mark::W);
			inc(winPos);							//now used to iterate
		}
		
		
	}
	
	return win;
		
}
bool GameBoard::inBounds(const Position &pos) const
{
	return((pos.row>=0)&&(pos.col>=0)&&(pos.row<=gameParams.NUMROWS-1)&&(pos.col<=gameParams.NUMCOLS-1));
}


			



		