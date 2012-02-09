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
	if((row>maxRow) || (col>maxCol)|| (row<0) || (col<0))	// invalid move
		return false;
	return gb->markBoard(row,col,myMark);					//mark Board w/ valid values
}
string Player::getName()
{
	return name;
}
Mark::Values Player::getMark()
{
	return myMark;
}
void Player::setName(string n)
{
	name=n;
	if (name != "Computer")
		myMove=humanMove;
}
void Player::setMark(Mark::Values m)
{
	myMark=m;
}
