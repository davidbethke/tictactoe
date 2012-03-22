#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H
#include <iostream>
template< typename T> class ArrayT;
template<typename T>
std::ostream &operator<<( std::ostream &os,  ArrayT<T> &a ) 
{
	a.print(os);
   return os; // enables cout << x << y;
} //
template<typename T>
std::istream & operator>>(std::istream &is, ArrayT<T> &a)
{
	a.input(is);
	return is;
}
#endif //ARRAYTHELPER_H
