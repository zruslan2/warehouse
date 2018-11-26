#include "appliances.h"

appliances::appliances(bool electric, string name, date_ d, double price)
	:product(name,d,price)
{
	this->electric = electric;
}

void appliances::setElectric(bool electric)
{
	this->electric = electric;
}
