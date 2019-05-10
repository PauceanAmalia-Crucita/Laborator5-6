#pragma once
#include "DynamicVector.h"
#include <string>

class ShoppingBasket /*: public DynamicVector<TrenchCoat>*/
{
private:
	DynamicVector<TrenchCoat> list;
public:
	void addShoppingBasket(const TrenchCoat& coat) noexcept
	{
		this->list.add(coat);
	}


	DynamicVector<TrenchCoat>& getAllShopping() noexcept {
		return this->list;
	}


	int getSize()
	{
		return list.getSize();
	}
};