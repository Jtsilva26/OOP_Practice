#include <iostream>

#include "stack.h"

using namespace std;

int main()
{
  Stack<int> s;
  s.push(5);
  s.push(10);
  s.push(1);
  s.push(11);
  cout << s.size() << endl;
  s.pop();
  cout << s.size() << endl;
  s.pop();
  cout << s.size() << endl;
  s.pop();
  cout << s.size() << endl;
  s.pop();
  cout << s.size() << endl;
}
