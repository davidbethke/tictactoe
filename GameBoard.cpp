#include "StdAfx.h"
#include "GameBoard.h"

#include <iostream>

using namespace std;
GameBoard::GameBoard(int r,int c,int rw, int fun):NUMOFROWS(r),NUMOFCOLS(c),INAROWTOWIN(rw),NUMBEROFFUNCS(fun),numberOfMarks(0)
{
	typedef  void(*myInc)(Position &);
	//init gameboard
	gameBoard= new GameSquare *[NUMOFROWS];
	for (int i=0; i<NUMOFROWS;++i)
		gameBoard[i]= new GameSquare[NUMOFCOLS];
	
	searchFunctionArr= new myInc[4];
	searchFunctionArr[0]=acrossInc;
	searchFunctionArr[1]=downInc;
	searchFunctionArr[2]=diagInc;
	searchFunctionArr[3]=diagDec;
	//clear values
	clearBoard();
}
/*
GameBoard::GameBoard():NUMOFROWS(3),NUMOFCOLS(3),numberOfMarks(0),INAROWTOWIN(3),NUMBEROFFUNCS(4)
{
	typedef  void(*myInc)(Position &);
	//init gameboard
	cout<<"GameBoard initing"<<std::endl;
	gameBoard= new GameSquare *[NUMOFROWS];
	for (int i=0; i<NUMOFROWS;++i)
		gameBoard[i]= new GameSquare[NUMOFCOLS];
	//init searchFuncArr
	searchFunctionArr= new myInc[4];
	searchFunctionArr[0]=acrossInc;
	searchFunctionArr[1]=downInc;
	searchFunctionArr[2]=diagInc;
	searchFunctionArr[3]=diagDec;
	//void(*searchFunctionArr[4])(Position &)={&acrossInc,&downInc,&diagInc,&diagDec};
	//clear values
	clearBoard();
}
*/


GameBoard::~GameBoard(void)
{
	//Clean up pointers
	for(int i=0; i< NUMOFROWS;++i)
			delete[] gameBoard[i];
	delete [] gameBoard;
}
bool GameBoard::checkFull() const
{
	return numberOfMarks == (NUMOFROWS*NUMOFCOLS);
}
void GameBoard::clearBoard()
{
	cout << "Clearing Board .."<<endl;
	//reset number of Marks
	numberOfMarks=0;
	for(int i=0; i<NUMOFROWS;++i)
	{
		for(int j=0; j<NUMOFCOLS;++j)
		{
			gameBoard[i][j].setValue(Mark::BLANK);
		}
	}
}
bool GameBoard::markBoard(int r, int c, Mark::Values mark)
{
	if(gameBoard[r][c].hasValue())
		return false;
	else
	{
		numberOfMarks++;
		return gameBoard[r][c].setValue(mark);
	}
}
/*
bool GameBoard::checkAll(Mark::Values &mark)
{
	//TODO maybe iterate over all enums, for now
	
	if(check(ACROSS,mark) || check(DOWN,mark) || check(DIAG,mark))
		return true;
	else
		return false;
}
bool GameBoard::checkAllNew(Mark::Values &mark)
{
	//mark=Mark::EX; //kluge for now
	Position start(0,0);
	Position endDown(NUMOFROWS-1,0);
	Position endAcross(0,NUMOFCOLS-1);
	Position endDiag(NUMOFROWS-1,NUMOFCOLS-1);
	//searchBunch(start,endAcross,NUMOFCOLS,downInc,acrossInc) ||
	return (searchBunch(start,endAcross,NUMOFCOLS,downInc,acrossInc,mark) ||
			searchBunch(start,endDown,NUMOFROWS,acrossInc,downInc,mark) ||
			searchBunch(start,endDiag,1,diagInc,diagInc,mark) ||
			searchBunch(endDown,endAcross,1,diagDec,diagDec,mark)
			);
	
}
*/
bool GameBoard::checkAllGeneric(Mark::Values &mark) 
{
	bool result=false;
	mark=Mark::BLANK;
	
	for(int i=0;i<NUMOFROWS;++i)
	{
		for(int j=0;j<NUMOFCOLS;++j)
		{
			for(int k=0;k<4;++k)
			{
				if(searchGeneric(Position(i,j),INAROWTOWIN,searchFunctionArr[k],mark))
						result=true;
			
			}
		}
	}
	
	return result;
}
/*
bool GameBoard::searchBunch(Position start, Position end,int range,void(*inc)(Position&),void(*fun)(Position&),Mark::Values&mark)
{
	bool result=false;
	for(int i=0; i<range;++i)
	{
		if(searchRange(start,end,INAROWTOWIN,fun,mark))
			result=true;
		inc(start);
		inc(end);
	}
	return result;

}
bool GameBoard::check(Direction d, Mark::Values &mark)
{
	switch(d)
	{
	case ACROSS:
		return checkAcross(mark);
		break;
	case DOWN:
		return checkDown(mark);
		break;
	case DIAG:
		return checkDiag(mark);
		break;
	default:
		return false;
		break;
	}
}
bool GameBoard::checkAcross(Mark::Values &mark)
{
	bool result=false;
	Mark::Values temp;
	int matchIndex;
	mark = Mark::BLANK;
	for (int i=0; i<NUMOFROWS;++i)
	{
				
		//if first val of the row is not blank, check the cols, otherwise go to next row
		if(gameBoard[i][0].hasValue())
		{
			matchIndex=0;
			temp=gameBoard[i][0].getValue();
			for(int j=1;j<NUMOFCOLS;++j)
			{
				if(temp == gameBoard[i][j].getValue() )
					matchIndex++;
			}
			if(matchIndex == NUMOFCOLS-1)
			{
				result=true;
				mark=temp;
			}
		}
	}
	return result;
}
bool GameBoard::checkDown(Mark::Values &mark)
{
	bool result=false;
	Mark::Values temp;
	int matchIndex;
	mark=Mark::BLANK;
	for (int i=0; i<NUMOFCOLS;++i)
	{
				
		//if first val of the col is not blank, check the rows, otherwise go to next col
		if(gameBoard[0][i].hasValue())
		{
			matchIndex=0;
			temp=gameBoard[0][i].getValue();
			for(int j=1;j<NUMOFROWS;++j)
			{
				if(temp == gameBoard[i][j].getValue() )
					matchIndex++;
			}
			if(matchIndex == NUMOFROWS-1)
			{
				result=true;
				mark=temp;
			}
		}
	}
	return result;
}
bool GameBoard::checkDiag(Mark::Values &mark)
{
	
	
	bool result=false;
	Mark::Values temp;
	int matchIndex;
	mark=Mark::BLANK;
	// check immediate falses
	//diag only works for symetric gameboards, ie numrows=numcols
	if(NUMOFCOLS != NUMOFROWS)
		return result;
	// check corners for blank
	if(gameBoard[0][0].isBlank())
		return result;
	if(gameBoard[0][NUMOFCOLS-1].isBlank())
		return result;

	//check first diag
	temp=gameBoard[0][0].getValue();
	matchIndex=0;
	for(int i=1; i<NUMOFCOLS;i++)
	{
		if(temp == gameBoard[i][i].getValue())
			matchIndex++;
	}
	if(matchIndex == NUMOFCOLS-1)
	{
		result=true;
		mark=temp;
	}

	//check second diag
	temp=gameBoard[0][NUMOFCOLS-1].getValue();
	matchIndex=0;
	for (int i=NUMOFCOLS-2; i<0;--i)
	{
		if(temp == gameBoard[i][i].getValue())
			matchIndex++;
	}
	if(matchIndex == NUMOFCOLS-1)
	{
		result=true;
		mark=temp;
	}


	return result;
}
*/
void GameBoard::displayBoard() const
{
	for (int i=0; i<NUMOFROWS;++i)
	{
		for(int j=0;j<NUMOFCOLS;++j)
			std::cout<<gameBoard[i][j].getSValue()<<"|";
		std::cout <<std::endl;
		std::cout <<"------"<<endl;
	}

}
bool GameBoard::checkBlank()
{
	bool result=true;
	for(int i=0; i<NUMOFROWS;++i)
	{
		for(int j=0;j<NUMOFCOLS;++j)
		{
			if(gameBoard[i][j].isBlank())
				result=false;
		}
	}
	return result;
}
int GameBoard::getMarks()
{
	return numberOfMarks;
}
bool GameBoard::searchGeneric(Position start,int inARow,void(*inc)(Position&),Mark::Values&mark)
{
	//while w/in the gameBoard,look for inARow matches for a win, otherwise lose
	bool result=false; 
	int matchCount=1;
	Mark::Values winningMark=Mark::BLANK;
	
	Position first(start); // start count position
	Position current(start);// variable count position, if current-start >= INAROW, then a win
	Position winPos(start);
	inc(current); // set current one before start to init

	while(inBounds(current))
	{
		if(gameBoard[first.row][first.col].isBlank()||gameBoard[first.row][first.col].getValue()==Mark::W)
		{
			// need a value, not blank
			inc(first);
			inc(current);
			matchCount=1;
		}
		else if(gameBoard[first.row][first.col].getValue() == gameBoard[current.row][current.col].getValue())
		{
			matchCount++;
			if(matchCount==inARow)
			{
				result=true;
				winningMark=gameBoard[first.row][first.col].getValue();
				mark=gameBoard[first.row][first.col].getValue();
				winPos=first;
			}
			inc(current);
			
			
		}
		else
		{
			//inc(first); // see if this helps diags
			first=current; // move fixed position 
			inc(current);  //inc current position
			matchCount=1;   // didn't match reset
		}
	}
	//update result to win if the matches=inARow game requirement

	if(result)
	{
		mark=winningMark;
		
		for(int i=0; i<inARow;++i)
		{
			//remark board so I can see the winner easily
			gameBoard[winPos.row][winPos.col].setValue(Mark::W);
			inc(winPos);//now used as a generic iterator
		}
		
		
	}
	
	return result;
	
}
bool GameBoard::inBounds(const Position &pos) const
{
	return((pos.row>=0)&&(pos.col>=0)&&(pos.row<=NUMOFROWS-1)&&(pos.col<=NUMOFCOLS-1));
}
/*
bool GameBoard::searchRange(Position start, Position end, int inARow, void(*inc)(Position&),Mark::Values&mark)
{
	bool result=false;
	int match=0;
	//
	//
	//Position first(start.row,start.col);
	//Position current(start.row,start.col);
	Position first(start);
	Position current(start);
	inc(current);
	inc(end);
	while(current != end)
	{
		if(gameBoard[first.row][first.col].isBlank())
		{
			// need a value, not blank
			inc(first);
			inc(current);
			match=0;
		}
		else if(gameBoard[first.row][first.col].getValue() == gameBoard[current.row][current.col].getValue())
		{
			inc(current);
			match++;
		}
		else
		{
			inc(first);
			inc(current);
			match=0;
		}

	}
	
	if(max(current.row-first.row,current.col-first.col)== inARow)
	{
		result=true;
		mark=gameBoard[first.row][first.col].getValue();
	}
		
	/*
	if(match==inARow-1)
		result=true;
		*/
/*
	return result;

}
*/
int GameBoard::max(int a, int b) const
{
	if (a>b)
		return a;
	else
		return b;
}


			



		