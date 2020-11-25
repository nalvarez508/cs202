//A signature Nick Alvarez program, created for Project 7 due April 3, 2019.
//This program dynamically allocates memory for strings.

#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

int main()
{
  //1
  cout << endl << "Testing: Default constructor" << endl << "**********" << endl;
  MyString ms_default;

  //2
  cout << endl << "Testing: Parameterized constructor" << endl << "**********" << endl;
  MyString ms_parametrized("MyString parametrized constructor!");

  //3
  cout << endl << "Testing: Copy constructor" << endl << "**********" << endl;
  MyString ms_copy(ms_parametrized);

  //4
  cout << endl << "Testing: Destructor" << endl << "**********" << endl;
  MyString * ms_Pt = new MyString("MyString to be deleted...");
  delete ms_Pt;
  ms_Pt = NULL;

  //5,6
  cout << endl << "Testing: size() and length()" << endl << "**********" << endl;
  MyString ms_size_length("Size and length test");
  cout << ms_size_length.size() << endl;
  cout << ms_size_length.length() << endl;

  //7
  cout << endl << "Testing: c_str()" << endl << "**********" << endl;
  MyString ms_toCstring("C-String equivalent successfully obtained!");
  cout << ms_toCstring.c_str() << endl;

  //8
  cout << endl << "Testing: Comparison operator overload" << endl << "**********" << endl;
  MyString ms_same1("The same"), ms_same2("The same");
  if (ms_same1 == ms_same2)
    cout << "Same success" << endl;

  MyString ms_different("The same (NOT)");
  if (!(ms_same1 == ms_different))
    cout << "Different success" << endl;

  //9
  cout << endl << "Testing: Assignment operator overload" << endl << "**********" << endl;
  MyString ms_assign("Before assignment");
  ms_assign = MyString("After performing assignment");

  //10
  cout << endl << "Testing: Addition operator overload" << endl << "**********" << endl;
  MyString ms_append1("The first part");
  MyString ms_append2(" and the second");
  MyString ms_concat = ms_append1 + ms_append2;

  //11
  cout << endl << "Testing: Bracket operator overload" << endl << "**********" << endl;
  MyString ms_access("Access successful (NOT)");
  ms_access[17] = 0;

  //12
  cout << endl << "Testing: Insertion operator overload" << endl << "**********" << endl;
  cout << ms_access << endl;

  return 0;
}
