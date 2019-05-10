#pragma once

#include "TrenchCoat.h"
#include<iostream>
using namespace std;
//typedef TrenchCoat TElement;
template <typename TElement>
class DynamicVector
{
private:
	TElement * elems;
	int size;
	int capacity;
public:
	DynamicVector(int capacity = 10);

	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);

	TElement & operator[](int pos);

	// Adds an element to the current DynamicVector
	void add(const TElement& e);

	int getSize() const;
	TElement* getAllElems() const;

	void del(const int& pos);

	void update(const int& pos, const TElement& elem) ;

	DynamicVector & operator+(const TElement & elem);



private:

	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number)
	void resize(double factor = 2);
};

template class DynamicVector<TrenchCoat>;