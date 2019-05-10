#include "DynamicVector.h"
template <typename TElement>
DynamicVector<TElement>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}


template <typename TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}


template <typename TElement>
DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename TElement>
TElement & DynamicVector<TElement>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename TElement>
void DynamicVector<TElement>::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size++] = e;
}


template <typename TElement>
void DynamicVector<TElement>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}


template <typename TElement>
int DynamicVector<TElement>::getSize() const { return this->size; }


template <typename TElement>
TElement* DynamicVector<TElement>::getAllElems() const { return this->elems; }


template <typename TElement>
void DynamicVector<TElement>::del(const int& pos)
{
	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;

		
}

template <typename TElement>
void DynamicVector<TElement>::update(const int & pos, const TElement & elem)
{
	this->elems[pos] = elem;
}


template <typename TElement>
DynamicVector<TElement> & DynamicVector<TElement> ::operator+(const TElement & e)
{
	add(e);
	return *this;

}


template <typename TElement>
DynamicVector<TElement>& operator+(TElement& e, DynamicVector<TElement>& v)
{
	v.add(e);
	return v;
}





