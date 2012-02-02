
#include <string>
#include <iostream>
#include <random>
#include "GameBoard.h"
#ifndef PLAYER
#define PLAYER
using namespace std;
class Player
{
public:
	Player(string);
	Player(void);
	~Player(void);
	int getNumberOfPlays();
	int getNumberOfWins();
	void setName(string);
	void setMark(Mark::Values);
	string getName();
	bool move(int, int, GameBoard*);
private:
	string name;
	int numberOfPlays;
	int numberOfWins;
	Mark::Values myMark;
	void (*myMove)(int &, int &, const int &, const int &);
};
void humanMove(int & row, int &col,const int & maxRow, const int &maxCol)
{
	
	cout << "Enter the row (Max Val is "<<maxRow<<")"<<endl;;
	cin >> row;
	cout << "Enter the col (Max Val is "<<maxCol<<")"<<endl;
	cin >> col;
}
void computerMove(int & row, int & col, const int & maxRow, const int &maxCol)
{
	row= rand()%maxRow;
	col= rand()%maxCol;
	std::cout<<"Im a Computer"<<std::endl;
	std::cout<<"Row:"<<row<<", Col:"<<col<<endl;
	//random move based on numcols, numrows
}

#endif