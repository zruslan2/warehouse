#include "date_.h"

date_::date_()
{
	this->day = 1;
	this->month = 1;
	this->year = 1900;
}

date_::date_(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

void date_::setDay(int day)
{
	if (day < 1 || day>31)
		this->day = 1;
	else
		this->day = day;
}

void date_::setMonth(int month)
{
	if (month < 1 || month>12)
		this->month = 1;
	else
		this->month = month;
}

void date_::setYear(int year)
{
	if (year < 1900)
		this->year = 1900;
	else
		this->year = year;
}

void date_::print()
{
	if (day < 10)
		cout << 0;
	cout << day << ".";
	if (month<10)
		cout << 0;
	cout << month << "." << year;
}

bool date_::IsLeap() const
{
	if (this->year % 4 == 0 && (this->year % 100 != 0 || this->year % 400 == 0)) return true;
	else return false;
}

int date_::maxday() const
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (IsLeap())days[1] = 29;
	return days[this->month - 1];
}

date_& date_::operator+=(int day)
{
	if (day + this->day>maxday()) {
		day -= maxday() - this->day;
		if (++this->month>12) {
			month = 1;
			year++;
		}
		while (double(day) / double(maxday())>1.0) {
			if (++this->month>12) {
				month = 1;
				year++;
			}
			day -= maxday();
		}
		this->day = day;
	}
	else this->day += day;
	return *this;
}

date_ & date_::operator-=(int day)
{
	if (this->day - day<1) {
		day -= this->day;
		if (--this->month == 0) {
			month = 12;
			year--;
		}
		while (double(day) / double(maxday())>1.0) {
			day -= maxday();
			if (--month == 0) {
				month = 12;
				year--;
			}
		}
		this->day = maxday() - day;
	}
	else this->day -= day;
	return *this;
}

string date_::getDateStr() const
{
	string d= "";
	d += to_string(day);
	d += ".";
	d += to_string(month);
	d += ".";
	d += to_string(year);
	return d;
}

bool operator<(const date_ & a, const date_ & b)
{
	if (a.getYear() > b.getYear()) return false;
	else if (a.getYear() < b.getYear()) return true;
	else if (a.getYear() == b.getYear())
	{
		if (a.getMonth() > b.getMonth())return false;
		else if (a.getMonth() < b.getMonth()) return true;
		else if (a.getMonth() == b.getMonth())
		{
			if (a.getDay() > b.getDay())return false;
			else if (a.getDay() < b.getDay()) return true;
		}
	}
	return false;
}

bool operator<=(const date_ & a, const date_ & b)
{
	if (a.getYear() > b.getYear()) return false;
	else if (a.getYear() < b.getYear()) return true;
	else if (a.getYear() == b.getYear())
	{
		if (a.getMonth() > b.getMonth())return false;
		else if (a.getMonth() < b.getMonth()) return true;
		else if (a.getMonth() == b.getMonth())
		{
			if (a.getDay() > b.getDay())return false;
			else if (a.getDay() < b.getDay()) return true;
			else if (a.getDay() == b.getDay()) return true;
		}
	}
	return false;
}

bool operator>(const date_ & a, const date_ & b)
{
	if (a.getYear() < b.getYear()) return false;
	else if (a.getYear() > b.getYear()) return true;
	else if (a.getYear() == b.getYear())
	{
		if (a.getMonth() < b.getMonth())return false;
		else if (a.getMonth() > b.getMonth()) return true;
		else if (a.getMonth() == b.getMonth())
		{
			if (a.getDay() < b.getDay())return false;
			else if (a.getDay() > b.getDay()) return true;
		}
	}
	return false;
}

bool operator>=(const date_ & a, const date_ & b)
{
	if (a.getYear() < b.getYear()) return false;
	else if (a.getYear() > b.getYear()) return true;
	else if (a.getYear() == b.getYear())
	{
		if (a.getMonth() < b.getMonth())return false;
		else if (a.getMonth() > b.getMonth()) return true;
		else if (a.getMonth() == b.getMonth())
		{
			if (a.getDay() < b.getDay())return false;
			else if (a.getDay() > b.getDay()) return true;
			else if (a.getDay() == b.getDay()) return true;
		}
	}
	return false;
}

bool operator==(const date_ & a, const date_ & b)
{
	return (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() == b.getDay());
}

bool operator!=(const date_ & a, const date_ & b)
{
	return (a.getYear() != b.getYear() || a.getMonth() != b.getMonth() || a.getDay() != b.getDay());
}


