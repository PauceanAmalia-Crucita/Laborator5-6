#include "TrenchCoat.h"
#include <Windows.h>
#include <shellapi.h>
#include<string>
#include<iostream>
using namespace std;

TrenchCoat::TrenchCoat() : size(0), colour(""), price(0), quantity(0), photograph(""){}
TrenchCoat::TrenchCoat(const int& size, const string& colour, const float& price, const int& quantity, const string& photograph)
{
	this->size = size;
	this->colour = colour;
	this->price = price;
	this->quantity = quantity;
	this->photograph = photograph;
}

void TrenchCoat::openPhotograph()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}

string TrenchCoat::toString()
{

	string str = "";
	str += "Size: ";
	str += to_string(this->size);
	str += ", colour: ";
	str += this->colour;
	str += ", price: ";
	str += to_string(this->price);
	str += ", of quantity";
	str += to_string(this->quantity);
	str += ", Photograph: ";
	str += this->photograph;

	return str;
}

TrenchCoat & TrenchCoat::operator=(const TrenchCoat & coat)
{
	this->size = coat.size;
	this->colour = coat.colour;
	this->price = coat.price;
	this->quantity = coat.quantity;
	this->photograph = coat.photograph;
	return *this;
}

int  TrenchCoat::operator==(const TrenchCoat & coat)
{
	if (this->getSize1() == coat.getSize1() && this->getPhotograph() == coat.getPhotograph())
		return 1;
	return 0;
}


