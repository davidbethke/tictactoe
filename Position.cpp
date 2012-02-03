
#include "StdAfx.h"
#include "Position.h"
Position::Position(int r,int c):row(r),col(c)
{
}
/*
Position::Position():row(0),col(0)
{
}
*/
Position::Position(const Position& other)
{
	//check for self assignment?
	row=other.row;
	col=other.col;
}
Position& Position::operator=(const Position& other)
{
	//self assignment check
	if(this == &other)
		return *this;
	row=other.row;
	col=other.col;
	return *this;
}
bool Position::operator==(Position & other)
{
	return ((row==other.row)&&(col==other.col));
}
bool Position::operator!=(Position & other)
{
	return !(*this==other);
}
Position Position::operator+(Position&other)
{
	return Position(row+other.row,col+other.col);
}
void Position::reset()
{
	row=col=0;
}
void acrossInc(Position& pos)
{
	(pos.col)++;
}
void downInc(Position& pos)
{
	(pos.row)++;
}
void diagInc(Position& pos)
{
	//upper left to lower right
	(pos.row)++;
	(pos.col)++;
}
void diagDec(Position& pos)
{
	// lower left to upper right
	(pos.row)--;
	(pos.col)++;
}



