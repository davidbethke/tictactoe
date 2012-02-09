#include "StdAfx.h"
#include "GameTypeHelper.h"
#include "Player.h"
#include <iostream>
using namespace std;
void swapPlayerIndex(int & a, int & b)
{
	int temp=a;
	a=b;
	b=temp;
}
void setPlayerOrder(int& first, int& second)
{
	char answer='n';
	cout<<"Swap Player Order y/n"<<endl;
	cin >> answer;
	if(answer=='y')
		swapPlayerIndex(first,second);
}
void setPlayerNames(Player ** p) 
{
	string name0="", name1="";
	// player 0
	cout <<"Enter Player 0 Name, enter 0 for Computer"<<endl;
	cin >> name0;
	if(name0 != "0")
		p[0]->setName(name0);
	
	cout <<"Enter Player 1 Name, enter 0 for Computer"<<endl;
	cin >> name1;
	if(name1 !="0")
		p[1]->setName(name1);
	//setMarks
	p[0]->setMark(Mark::OH);
	p[1]->setMark(Mark::EX);
}
