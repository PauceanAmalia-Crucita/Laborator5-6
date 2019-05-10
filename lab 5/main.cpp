#include"TrenchCoat.h"
#include "UI.h"
#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	system("color f4");
	TrenchRepository repo{};

	TrenchCoat c1{ 40, "blue", 120, 3, "a" };
	TrenchCoat c2{ 34, "pink", 560, 1,"b" };
	TrenchCoat c3{ 38, "green", 700, 0 ,"c" };
	repo.add(c1);
	repo.add(c2);
	repo.add(c3);

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;

}