//A signature Nick Alvarez program, made with a lack of sleep and for
//Project 8 for CS202.
//It's supposed to test linked lists.

#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main()
{
  DataType data1(1, 2.0);
  DataType data2(2, 4.0);
  DataType data3(3, 6.0);
  DataType data4(4, 8.0);
  DataType data5(5, 10.0);
  NodeList nodelist(5, data1);
  Node *tmp = NULL;
  nodelist[0] = data2;
  nodelist[3] = data3;

  cout << nodelist << endl;

  cout << endl << "Testing erase() function" << endl << endl;
  while ((tmp = nodelist.erase(data1)));
  cout << nodelist << endl;

  cout << endl << "Testing clear() function" << endl << endl;
  NodeList nodelist2;
  nodelist.clear();
  cout << nodelist << endl;

  return 0;
}
