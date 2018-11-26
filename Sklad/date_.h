#pragma once
#include <iostream>
using namespace std;

class date_
{
	int day;
	int month;
	int year;
public:
	date_();
	date_(int day, int month, int year);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	void print();
	// home work final class
	bool IsLeap()const;
	int maxday()const;
	date_& operator+=(int day);
	date_& operator-=(int day);

};
// home work
bool operator<(const date_&a, const date_&b);
bool operator<=(const date_&a, const date_&b);
bool operator>(const date_&a, const date_&b);
bool operator>=(const date_&a, const date_&b);
bool operator==(const date_&a, const date_&b);
bool operator!=(const date_&a, const date_&b);






