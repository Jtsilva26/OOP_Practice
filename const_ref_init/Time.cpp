#include "Time.h"
#include<iostream>
#include<iomanip>
using namespace std;

Time::Time(const Time& arg)
  :hour(arg.hour), minute(arg.minute)
{
  cerr << "Time: Copy ctor" << endl;
}

Time::Time(int hr, int min)
  :hour(hr), minute(min)
{
  cerr << "Time: 2-arg ctor" << endl;
}

void Time::display() const{
  cout << setfill('0');
  cout << setw(2) << hour << ':';
  cout << setw(2) << minute << endl;
}
