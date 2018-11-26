#pragma once
#include <string>
#include <iostream>
#include "date_.h"
using namespace std;

class product abstract
{
	string name;
	date_ d;
	double price;
public:
	product(string name, date_ d, double price);
	void setName(string name);
	void setDate(int y, int m, int d);
	void setPrice(double price);

	string getName()const { return name; }
	date_ getDate()const { return d; }
	double getPrice()const { return price; }
};

