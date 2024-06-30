#include "Report.h"
#include <iostream>
using namespace std;

//copy constructor
Report::Report(const Report& arg)
  : rep_date(arg.rep_date), rep_time(arg.rep_time), rep_desc(arg.rep_desc)
{
  cerr << "Report: Copy ctor" << endl;
}

// constructor with 6 arguments to create a report


// write Report's display function
void Report::display() const{
  rep_date.display();
  rep_time.display();
  cout << rep_desc << endl;
}
