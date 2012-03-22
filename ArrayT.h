#ifndef ARRAYT_H
#define ARRAYT_H
#include "ArrayTHelper.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
// Portions gratuitously copied from Array.h, Array.cpp

template< typename T>
class ArrayT
{
public:
	ArrayT(void);
	ArrayT(int, T initValue=T());   // default value calls default constructor of type T
	ArrayT(const ArrayT<T> &);
	~ArrayT(void);
	int getSize() const;
	const ArrayT<T>& operator=(const ArrayT<T>&);
	bool operator==(const ArrayT<T> & ) const;
	bool operator!=(const ArrayT<T>& ) const;
	T& operator[](int);
	T operator[](int) const;
	void print(std::ostream&);
	void input(std::istream&);
private:
	int size;
	T  *ptr;
	
};
template< typename T>
ArrayT<T>::ArrayT():ptr(NULL),size(0)
{
}

template< typename T>
ArrayT<T>::ArrayT(int arraySize, T initValue)
{
	if (arraySize >0)
		size=arraySize;
	else
		throw invalid_argument("Array size must be greater than 0");
	ptr = new T[size];

	for (int i=0; i < size; ++i)
		ptr[i]=initValue;
}
// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
template< typename T>
ArrayT<T>::ArrayT( const ArrayT<T> &arrayToCopy ): size( arrayToCopy.size )
{
   ptr = new T[ size ]; // create space for pointer-based array, type T

   for ( int i = 0; i < size; ++i )
	  ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
} // end Array copy constructor

template< typename T>
ArrayT<T>::~ArrayT()
{
   delete [] ptr; // release pointer-based array space
} // end destructor
// return number of elements of Array

template< typename T>
int ArrayT<T>::getSize() const
{
   return size; // number of elements in Array
} // end function getSize

template< typename T>
const ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>&right)
{
	if(&right !=this)  //self assign
	{
		if(size !=right.size)
		{
			delete [] ptr;
			size=right.size;
			ptr= new T[size];
		}
		for ( int i=0; i< size; ++i)
			ptr[i]=right.ptr[i];

	}
	return *this;
}

template< typename T>
bool ArrayT<T>::operator==(const ArrayT<T> & right) const
{
	if(size !=right.size)
		return false;
	for(int i=0; i< size; ++i)
		if(ptr[i] != right.ptr[i])
		return false;
	return true;
}
template< typename T>
T& ArrayT<T>::operator[](int subscript)
{
	if(subscript<0 || subscript >=size)
		throw out_of_range("Subscript out of range");
	return ptr[subscript];
}
template< typename T>
T ArrayT<T>::operator[](int subscript) const
{
	if(subscript<0 || subscript >=size)
		throw out_of_range("Subscript out of range");
	return ptr[subscript];
}
template< typename T>
bool ArrayT<T>::operator!=(const ArrayT<T>&) const
{
	return !(*this == right);
}
template< typename T>
void ArrayT<T>::print(std::ostream& os) 
{
	for(int i=0; i<size;++i)
		os<< ptr[i] << " ";
}
template< typename T>
void ArrayT<T>::input(std::istream& is)
{
	//std::cout<< "input called"<<size<<endl;
	for(int i=0; i< size;++i)
	{
		is >> ptr[i];
		//cout <<ptr[i];
	}
}


#endif //ARRAYT_Hwoody2000
