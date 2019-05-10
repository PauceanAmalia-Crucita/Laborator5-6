
#pragma once
#include "DynamicVector.h"
#include<iostream>
using namespace std;

class TrenchRepository
{
private:
	DynamicVector<TrenchCoat>  coats;
	int curentPos;

public:
	TrenchRepository();

	/*Add a coat to repository
	Input: coat-TrenchCoat
	Output: return 1 if the coat is added 
	        return 0 if the coat is not added*/
	bool add(const TrenchCoat& coat);

	/*Verify if the coat exist
	Input: givenPhotograph- string
	Output: return i- the position of the coat if the coat exists
	        return -1 is the coat does not exists*/
	int existsCoat(const string& givenPhotograph);

	/*Delete a coat to repository
	Input: coat-TrenchCoat
	Output: return 1 if the coat is deleted
			return 0 if the coat is not deleted*/
	bool delCoat(const string& givenPhotograph);


	/*Update the coat 
	Input:photo-string, newphoto- string, size-int, price- float, colour-string , quantity-int
	Output:-*/
	bool updateCoat(const string & photo, const string & newphoto, const int size, const float price, const string & colour, const int quantity);

	/*Get length of the coats list*/
	int getLength() const { return this->coats.getSize(); };

	/*Get all the coats*/
	TrenchCoat* getAll() const { return this->coats.getAllElems(); }

	/*Get elements of the list of the coats.*/
	DynamicVector<TrenchCoat> getCoats() const { return this->coats; }

	int isEmpty();

	DynamicVector<TrenchCoat> getCoatsBySize(int givenSize);

	TrenchCoat getCurentCoat();
	int getCurentPos();

	void nextCoat();
};

