#include "Controller.h"
#include "DynamicVector.h"

bool Controller::addCoatCtrl(const int & size, const string & colour, const float & price,int& quantity, const string & photograph)
{
	TrenchCoat coat{ size, colour, price , quantity,photograph };

	return this->repo.add(coat);
}

bool Controller::delCoatCtrl(const string& givenPhotograph)
{
	return this->repo.delCoat(givenPhotograph);
}

bool Controller::updateCoatCtrl(const string&photo, const string&newphoto, const int size, const float price, const string&colour, const int quantity)
{
	return this->repo.updateCoat(photo, newphoto, size, price, colour, quantity);
}

DynamicVector<TrenchCoat> Controller::getCoatsBySizeCtrl(int givenSize)
{
	return this->repo.getCoatsBySize(givenSize);
}

TrenchCoat Controller::getCurentCoatCtrl()
{
	return this->repo.getCurentCoat();;
}

void Controller::addCoatBasket()
{
	
	float s = 0;
	TrenchCoat coat;
	coat = this->getCurentCoatCtrl();
	this->list.addShoppingBasket(coat);
	//s += coat.getPrice();
	for (int i = 0; i <= list.getSize(); i++)
		s+= list.getAllShopping()[i].getPrice();
	cout << "The sum is: " << s << endl;
	this->repo.nextCoat();
	
}

void Controller::nextCoatCtrl()
{
	this->repo.nextCoat();
}

DynamicVector<TrenchCoat> Controller::getBasketballCoats()
{
	return this->list.getAllShopping();
}
