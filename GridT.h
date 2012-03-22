#ifndef GRIDT_H
#define GRIDT_H
#include "GridTHelper.h"
#include "ArrayT.h"
template< typename T>
class GridT
{
public:
	GridT(int=10,int=10);
	~GridT(void);
	GridT(const GridT<T>&);
	GridT<T>& operator=(const GridT<T>&);
	int getRows() const;
	int getCols() const;
	ArrayT<T>& operator[](int);
	const ArrayT<T>& operator[](int) const;
	void print(std::ostream&) const;
private:
	ArrayT<T> * myGrid;
	int nRows;
	int nCols;
	bool inBounds(int) const;
};
template< typename T>
GridT<T>::GridT(int r, int c):nRows(r), nCols(c)
{
	myGrid= new ArrayT<T>[nRows];
	for(int i=0; i<nRows; ++i)
		myGrid[i]=ArrayT<T>(nCols);
}
template< typename T>
GridT<T>::~GridT(void)
{
	delete[] myGrid;
}
template< typename T>
GridT<T>::GridT(const GridT<T> & other)
{
	nRows=other.nRows;
	nCols=other.nCols;
	myGrid= new ArrayT<T>[other.nRows];
	for (int i=0; i<nRows; ++i)
		myGrid[i]=ArrayT<T>(other.myGrid[i]); //use copy constructor of ArrayT
}
template< typename T>
GridT<T>& GridT<T>::operator=(const GridT<T> & other)
{
	if(this !=&other)
	{
		delete[] myGrid;
		myGrid= new ArrayT<T>[other.nRows];
		nRows=other.nRows;
		nCols=other.nCols;
		for(int i=0;i<nRows;++i)
			myGrid[i]=ArrayT<T>(other.myGrid[i]); //ArrayT copy constructor
	}
	return *this;
}

template< typename T>
int GridT<T>::getRows() const
{
	return nRows;
}
template< typename T>
int GridT<T>::getCols() const
{
	return nCols;
}

template< typename T>
ArrayT<T>& GridT<T>::operator[](int i)
{
	if(inBounds(i))
		return myGrid[i];
	else
		throw out_of_range("Subscript out of range");
}
template< typename T>
const ArrayT<T>& GridT<T>::operator[](int i) const
{
	if(inBounds(i))
		return myGrid[i];
	else
		throw out_of_range("Subscript out of range");
}
template< typename T>
bool GridT<T>::inBounds( int i) const
{
	return (i>=0&&i<nRows);
}
template< typename T>
void GridT<T>::print(std::ostream& os) const
{
	for(int i=0; i<nRows;++i)
		os << myGrid[i] <<endl;
}

#endif //GRIDT_H