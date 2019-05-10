#include "UI.h"
#include<string>

using namespace std;


void UI::printMenu(int option)
{

	if (option == 1) {
		cout << endl;
		cout << "1- Add a trench coat." << endl;
		cout << "2- Display all trench coats." << endl;
		cout << "3- Delete coats by quantity." << endl;
		cout << "4- Update a coat." << endl;
		cout << "0- Exit." << endl;	

	}
	else if (option == 2) {
		cout << endl;
		cout << "1- See the trench coats having a given size." << endl;
		cout << "2- Add the trench to the shopping basket." << endl;
		cout << "3- Next coat." << endl;
		cout << "4- See the shopping basket and the total price of the items." << endl;
		cout << "5- Change option." << endl;
		cout << "0- Exist" << endl;

	}
}

void UI::readInteger(int &x)
{
	cout << "Choose an option: ";
	cin >> x;
	
	cout << endl;
	while (x < 0 || x>6) {
		cout << "Choose an option: ";
		cin >> x;
		cout << endl;
	}
	cout << endl;
}

void UI::getCoatsBySizeUI()
{
	int givenSize;
	cin.ignore();
	cout << "Insert a size: ";
	cin >> givenSize;
	cout << endl;
	DynamicVector<TrenchCoat> coats = ctrl.getCoatsBySizeCtrl(givenSize);
	int i;
	for (i = 0; i < coats.getSize(); i++) {
		string str;
		str = coats[i].toString();
		cout << str << endl;
	}
}

void UI::getCurentCoatUI()
{
	TrenchCoat coat = this->ctrl.getCurentCoatCtrl();
	string str;
	str = coat.toString();
	cout << str << endl;
}

void UI::addCoatBasketUI()
{
	this->ctrl.addCoatBasket();
}

void UI::nextCoatUI()
{
	this->ctrl.nextCoatCtrl();
}

void UI::getBasketballCoatsUI()
{
	DynamicVector<TrenchCoat> coats = this->ctrl.getBasketballCoats();
	int i;
	float s = 0;
	for (i = 0; i < coats.getSize(); i++) {
		string str;
		str = coats[i].toString();
		cout << str << endl;
		s += coats[i].getPrice();
		//cout << "The sum is: " <<s<< endl;

	}
	cout << "The sum is: " << s << endl;

}


void UI::run()
{
	int option = -1;
	while (option) {

		cout << "1- Admin  " << endl;
		cout << "2- User  " << endl;
		cout << "Your option is: ";
		cin >> option;
		while (option != 1 && option != 2) {
			cout << "You can only choose 1 or 2" << endl;
			cout << "Your option is: ";
			cin >> option;
			cout << endl;
		}

		cout << endl;
		if (option == 1) {
			int option2 = -1;
			while (option2 != 0) {
				this->printMenu(option);
				this->readInteger(option2);

				if (option2 == 1)
				{
					this->addCoatUI();
					cout << endl;
				}

				else if (option2 == 2)
				{
					this->displayAllCoatsUI();
					cout << endl;
				}

				else if (option2 == 3)
				{
					this->delCoatUI();
					cout << endl;
				}

				else if (option2 == 4)
				{
					this->updateCoatUI();
					cout << endl;
				}

				else if (option2 == 0)
				{
					option = 0;
					break;
				}


			}

		}
		if (option == 2) {
			int option2 = -1;
			while (option2 != 0) {
				this->printMenu(option);
				this->readInteger(option2);

				if (option2 == 1)
				{
					this->getCoatsBySizeUI();
					cout <<  endl;
				}
				else if (option2 == 2)
				{
					this->addCoatBasketUI();
					
					cout <<  endl;
				}
				else if (option2 == 3)
				{
					this->nextCoatUI();
					cout <<  endl;
				}
				else if (option2 == 4)
				{
					this->getBasketballCoatsUI();
					cout <<  endl;
				}
				else if (option2 == 5) {
					option = 1;
					break;
				}
				else if (option2 == 0) {
					option = 0;
					break;

				}

			}


		}
		if (option == 0)
			break;
	}


	
}



void UI::addCoatUI()
{
	cout << "Give a size: ";
	int size = 0;
	cin >> size;
	getchar();
	cout << "Give a colour: ";
	string colour;
	getline(cin, colour);
	
	cout << "Give a price: ";
	float price = 0;
	cin >> price;
	getchar();
	cout << "Give a quantity: ";
	int quantity = 0;
	cin >> quantity;
	getchar();
	cout << "Give a photograph: ";
	string photograph;
	getline(cin, photograph);

	
	bool res=this->ctrl.addCoatCtrl(size, colour, price, quantity, photograph);
	if (res == true)
		cout << "The coat was added.\n";
	else
		cout << "The coat was not added.\n";
	

}

void UI::delCoatUI()
{
	cout << "Give a photograph: ";
	string photograph;
	cin.ignore();
	getline(cin, photograph);
	bool res= this->ctrl.delCoatCtrl(photograph);
	if (res == true)
		cout << "The coat was deleted.\n";
	else
		cout << "The coat was not deleted.\n";
}

void UI::updateCoatUI()
{

	cout << "Give a photograph: ";
	string photo;
	getchar();
	getline(cin, photo);
	cout << "Give a new photo: ";
	string newphoto;

	getline(cin, newphoto);
	cout << "Give a size: ";
	int size = 0;
	cin >> size;
	getchar();
	cout << "Give a colour: ";
	string colour;
	getline(cin, colour);
	cout << "Give a price: ";
	float price = 0;
	cin >> price;
	getchar();
	cout << "Give a quantity: ";
	int quantity = 0;
	cin >> quantity;
	getchar();
	bool res=this->ctrl.updateCoatCtrl(photo, newphoto, size, price, colour, quantity);
	if (res == true)
		cout << "The coat was updated.\n";
	else
		cout << "The coat was not updated.\n";
}


void UI::displayAllCoatsUI()
{
	
	//DynamicVector v = this->ctrl.getRepo().getCoats();
	TrenchCoat* coats = ctrl.getAllCtrl();

	if (coats == NULL)
		return;

	if (this->getLengthUi() == 0) {
		cout << "There are no coats to display." << endl;
		return;
	}

	for (int i = 0; i < this->getLengthUi(); i++)
	{
		TrenchCoat c = coats[i];
		cout << c.getSize1()<<"  " << c.getColour() << " " << c.getPrice() << " "<< c.getQuantity()<<" " <<c.getPhotograph()<< endl;
	}
}
