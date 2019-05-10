#pragma once
#include<iostream>
using namespace std;

class TrenchCoat
{
private:
	int size;
	string colour;
	float price;
	int quantity;
	string  photograph;
public:
	TrenchCoat();
	TrenchCoat(const int& size, const string& colour, const float& price,const int& quantity, const string& photograph);
	/*Get size of the coat
	Input: -
	Output:-
	*/
	int getSize1() const{ return this->size; }
	
	/*Get the colour of the coat
	Input:-
	Output:-*/
	string getColour() const { return this->colour; }

	/*Get price of the coat
	Input:-
	Output:-
	*/
	float getPrice() const { return this-> price; }

	/*Get quantity of the coat
	Input:-
	Output:-
	*/
	int getQuantity() const { return this->quantity; }

	/*Get photograph of the coat
	Input:-
	Output:-*/
	string getPhotograph() const { return this->photograph; }

	/*Open the photograph
	Input:-
	Output:-
	*/
	void openPhotograph();

	/*Get the string*/
	string toString();

	TrenchCoat &operator=(const TrenchCoat &coat);

	int operator==(const TrenchCoat & coat);
};
