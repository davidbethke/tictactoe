#include "StdAfx.h"
#include "PlayerHelper.h"
#include <random>
#include <iostream>
using namespace std;
void humanMove(int & row, int &col,const int & maxRow, const int &maxCol)
{
	std::cout << "Enter the row (Max Val is "<<maxRow<<")"<<std::endl;;
	std::cin >> row;
	std::cout << "Enter the col (Max Val is "<<maxCol<<")"<<std::endl;
	std::cin >> col;
}
void computerMove(int & row, int & col, const int & maxRow, const int &maxCol)
{
	row= rand()%maxRow;			//random move based on numcols, numrows
	col= rand()%maxCol;
	std::cout<<"ComputerPlayer"<<std::endl;
	std::cout<<"Row:"<<row<<", Col:"<<col<<std::endl;
}
