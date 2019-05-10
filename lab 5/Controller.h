#pragma once
#include"TrenchRepository.h"
#include"ShoppingBasket.h"
using namespace std;

class Controller
{
private:
	TrenchRepository repo;
	ShoppingBasket list;
public:
	Controller(const TrenchRepository& repo) : repo(repo) {}

	TrenchRepository getRepo()const { return this->repo; }

	/*Add a coat from repository to controller
	Input: coat-TrenchCoat
	Output: return 1 if the coat is added
			return 0 if the coat is not added*/
	bool addCoatCtrl(const int& size, const string& colour, const float& price, int& quantity,const string& photograph);

	/*Delete a coat from repository to controller
	Input: coat-TrenchCoat
	Output: return 1 if the coat is added
			return 0 if the coat is not added*/
	bool delCoatCtrl(const string& givenPhotograph);

	/*Update a coat from repository to controller
	Input: coat-TrenchCoat
	Output: return 1 if the coat is added
			return 0 if the coat is not added*/
	bool updateCoatCtrl(const string & photo, const string & newphoto, const int size, const float price, const string & colour, const int quantity);

	/*Function that returns the number of coats objects in repository*/
	int getLengthCtrl() const { return this->repo.getLength(); };

	DynamicVector<TrenchCoat> getCoatsBySizeCtrl(int givenSize);

	TrenchCoat getCurentCoatCtrl();

	void addCoatBasket(int s);

	

	TrenchCoat* getAllCtrl()const { return this->repo.getAll(); }

	void addCoatBasket();

	void nextCoatCtrl();

	DynamicVector<TrenchCoat> getBasketballCoats();
};