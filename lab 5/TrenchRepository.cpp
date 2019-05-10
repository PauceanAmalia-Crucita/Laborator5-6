#include "TrenchRepository.h"
#include<iostream>
#include<string>
using namespace std;
TrenchRepository::TrenchRepository()
{
	this->curentPos = 0;

}



bool TrenchRepository::add(const TrenchCoat& coat)
{
	if (existsCoat(coat.getPhotograph()) == -1)
	{
		this->coats.add(coat);
		return true;
	}
	return false;
}

int TrenchRepository::existsCoat(const string & givenPhotograph)
{
	TrenchCoat* coats = this->coats.getAllElems();
	for (int i = 0; i < this->coats.getSize(); i++)
	{
		if (this->coats[i].getPhotograph() == givenPhotograph)
			return i;
	}
	return -1;
}

bool TrenchRepository::delCoat(const string& givenPhotograph)
{
	int res = existsCoat(givenPhotograph);
	if (res != -1)
	{
		this->coats.del(res);
		return true;
	}
	return false;
}

bool TrenchRepository::updateCoat(const string&photo, const string&newphoto, const int size, const float price, const string&colour, const int quantity)
{
	TrenchCoat coat{ size, colour,price,quantity,newphoto };
	int res = existsCoat(photo);
	if (res != -1)
	{
		this->coats.update(res, coat);
		return true;
	}
	return false;
}

int  TrenchRepository::isEmpty()
{
	if (this->coats.getSize() == 0)
		return 0;
	return 1;
}

void TrenchRepository::nextCoat()
{
	if (this->isEmpty() != 0)
		this->curentPos++;
}


DynamicVector<TrenchCoat> TrenchRepository::getCoatsBySize(int givenSize)
{
	DynamicVector<TrenchCoat> list;
	int i;
	for (i = 0; i < this->coats.getSize(); i++)
		if (this->coats[i].getSize1() == givenSize)
			list.add(coats[i]);
	return list;
}

TrenchCoat TrenchRepository::getCurentCoat()
{
	if (this->curentPos == this->coats.getSize())
		this->curentPos = 0;
	return this->coats[this->curentPos];
}



int TrenchRepository::getCurentPos()
{
	return this->curentPos;
}