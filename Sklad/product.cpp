#include "product.h"



product::product(string name, date_ d, double price)
{
	this->name = name;
	this->d = d;
	this->price = price;
}

void product::setName(string name)
{
	this->name = name;
}

void product::setDate(int y, int m, int d)
{
	this->d.setDay(d);
	this->d.setMonth(m);
	this->d.setYear(y);
}

void product::setPrice(double price)
{
	this->price = price;
}
