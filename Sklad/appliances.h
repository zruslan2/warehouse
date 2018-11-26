#pragma once
#include "product.h"
class appliances :
	public product
{
	bool electric=true;
public:
	appliances(bool electric, string name, date_ d, double price);

	void setElectric(bool electric);

	bool getElectric()const { return electric; }
};

