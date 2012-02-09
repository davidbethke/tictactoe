#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <time.h>
#include <random>
#include "Mark.h"

class GameBoard;
class Player
{
public:
	Player(std::string n="Computer"); //default Player is Computer
	~Player(void);
	//int getNumberOfPlays();
	//int getNumberOfWins();
	void setName(std::string);
	void setMark(Mark::Values);
	Mark::Values getMark();
	std::string getName();
	bool move(int, int, GameBoard*);
private:
	std::string name;
	//int numberOfPlays;
	//int numberOfWins;
	Mark::Values myMark;
	void (*myMove)(int &, int &, const int &, const int &);
};
void humanMove(int & row, int &col,const int & maxRow, const int &maxCol)
{
	
	std::cout << "Enter the row (Max Val is "<<maxRow<<")"<<std::endl;;
	std::cin >> row;
	std::cout << "Enter the col (Max Val is "<<maxCol<<")"<<std::endl;
	std::cin >> col;
}
void computerMove(int & row, int & col, const int & maxRow, const int &maxCol)
{
	//srand(time(NULL));			// more random? set seed based on time, found online
	row= rand()%maxRow;			//random move based on numcols, numrows
	col= rand()%maxCol;
	std::cout<<"ComputerPlayer"<<std::endl;
	std::cout<<"Row:"<<row<<", Col:"<<col<<std::endl;
	
}

#endif