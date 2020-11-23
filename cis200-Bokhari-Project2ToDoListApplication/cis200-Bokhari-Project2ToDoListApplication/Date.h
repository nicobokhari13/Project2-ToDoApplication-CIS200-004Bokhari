#pragma once
using namespace std; 
#include <iostream>
#include <fstream>
struct Date {
public:
	Date() {};
	Date(int m, int d, int y) { setMonth(m); setDay(d); setYear(y); }
	~Date() {};
	friend ostream& operator<<(ostream& out, Date date) {
		out << date.getMonth() << " " << date.getDay() << " " << date.getYear();
		return out;
	}
	void setMonth(int m) { month = m; }
	void setDay(int d) { day = d; }
	void setYear(int y) { year = y; }
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }
	void copyDate(Date copy) {
		setDay(copy.getDay());
		setMonth(copy.getMonth());
		setYear(copy.getYear());
	}
	bool operator<(Date compare) {//less than means earlier 
		if (this->year < compare.getYear()) {
			return true;//if the year is earlier
		}
		else {
			if(this->year == compare.getYear()) {
				if (this->month < compare.getMonth()) {
					return true;
				}
				else {
					if (this->month == compare.getMonth()) {
						if (this->day < compare.getDay()) {
							return true; 
						}
					}
				}
			}
			return false; //if the year is greater, month is greater, or day is greater
		}
	}

private:
	int month;
	int day;
	int year;
};
