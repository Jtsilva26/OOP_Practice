#include "Date.h"
#include<iostream>
#include<iomanip>
using namespace std;

Date::Date(const Date& arg)
  :month(arg.month), day(arg.day), year(arg.year)
{
  cerr << "Date: Copy ctor" << endl;
}

Date::Date(int m, int d, int y)
  :month(m), day(d), year(y)
{
  cerr << "Date: 3-arg ctor" << endl;
}

void Date::display() const{
  cout << month << '/';
  cout << day << '/';
  cout << year << endl;
}
