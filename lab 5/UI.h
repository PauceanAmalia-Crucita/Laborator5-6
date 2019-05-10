#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu(int option);

	/*Add a coat from controller to Ui
	Input: -
	Output: -
	*/
	void addCoatUI();

	/*Delete a coat from controller to Ui
	Input: -
	Output: -
	*/
	void delCoatUI();

	/*Update a coat from controller to Ui
	Input: -
	Output: -
	*/
	void updateCoatUI();


	/*Display all coats from controller to Ui
	Input: -
	Output: -
	*/
	void displayAllCoatsUI();

	/*Get length of the elemets of the controller*/
	int getLengthUi() const { return this->ctrl.getLengthCtrl(); };

	/*Read an integer number for options.*/
	void readInteger(int &x);


	void getCoatsBySizeUI();

	void getCurentCoatUI();

	void addCoatBasketUI();

	void nextCoatUI();

	void getBasketballCoatsUI();
};
