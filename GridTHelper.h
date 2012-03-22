#ifndef GRIDTHELPER_H
#define GRIDTHELPER_H
#include "GridT.h"
#include <iostream>
using namespace std;
template< typename T> class GridT;
template< typename T>
std::ostream& operator<<(std::ostream& os,const GridT<T>&g)
{
	g.print(os);
	return os;
}
#endif//GRIDTHELPER_H
