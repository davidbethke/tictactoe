#include "StdAfx.h"
#include "Player.h"
#include "GameBoard.h"
using namespace std;


Player::Player(string n):name(n),numberOfPlays(0),numberOfWins(0)
{
	if (name == "Computer")
		myMove= computerMove;
}

Player::~Player(void)
{
}
int Player::getNumberOfPlays()
{
	return numberOfPlays;
}
int Player::getNumberOfWins()
{
	return numberOfWins;
}
bool Player::move(int maxRow, int maxCol,GameBoard * gb)
{
	int row, col;
	myMove(row,col,maxRow,maxCol);
	if((row>maxRow) || (col>maxCol)|| (row<0) || (col<0))
		return false;
	//mark Board w/ valid values
	return gb->markBoard(row,col,myMark);
}
string Player::getName()
{
	return name;
}
void Player::setName(string n)
{
	name=n;
	myMove=humanMove;
}
void Player::setMark(Mark::Values m)
{
	myMark=m;
}
