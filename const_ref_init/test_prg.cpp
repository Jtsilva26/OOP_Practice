#include "Report.h"
void report_on_current_status(const Report& status) //copy ctor
{
  status.display();
}


int main()
{
  Report red_folder(7,4,1776,10,15, "Coffee break");

  report_on_current_status(red_folder);
}
