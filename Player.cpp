#include "StdAfx.h"
#include "Player.h"
#include "GameBoard.h"
using namespace std;


Player::Player(string n):name(n)
{
	if (name == "Computer")
		myMove= computerMove;
}
Player::~Player(void)
{
}
bool Player::move(int maxRow, int maxCol,GameBoard * gb)
{
	int row, col;
	myMove(row,col,maxRow,maxCol);
	//myMove(row,col,gb->,maxCol);
	if((row>maxRow) || (col>maxCol)|| (row<0) || (col<0))	// invalid move
		return false;
	return gb->markBoard(row,col,myMark);					//mark Board w/ valid values
}
bool Player::move(GameBoard * gb)
{
	return move(gb->gameParams.NUMROWS,gb->gameParams.NUMCOLS,gb);
}

string Player::getName()
{
	return name;
}
Mark Player::getMark()
{
	return myMark;
}
void Player::setName(string n)
{
	name=n;
	if (name != "Computer")
		myMove=humanMove;
}
void Player::setMark(Mark m)
{
	myMark=m;
}
