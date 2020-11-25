//A signature Nick Alvarez program, created for Project 10 of CS202, due 5/1/19
//Test driver for stack classes

#include <iostream>
#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

int main()
{
  cout << "Testing Node Stack class..." << endl;

  cout << endl << "Default constructor" << endl;
  NodeStack<int> ns_d_i;
  NodeStack<double> ns_d_d;
  cout << ns_d_i << endl;
  cout << ns_d_d << endl;

  cout << endl << "Parameterized constructor" << endl;
  NodeStack<int> ns_p_i(3, 3);
  NodeStack<double> ns_p_d(4.0, 4.4);
  cout << ns_p_i << endl;
  cout << ns_p_d << endl;

  cout << endl << "Copy constructor" << endl;
  NodeStack<int> ns_c_i(ns_p_i);
  NodeStack<double> ns_c_d(ns_p_d);
  cout << ns_c_i << endl;
  cout << ns_c_d << endl;

  cout << endl << "Assignment operator overload" << endl;
  NodeStack<int> ns_a_i;
  NodeStack<double> ns_a_d;
  ns_a_i = ns_p_i;
  ns_a_d = ns_p_d;
  cout << ns_a_i << endl;
  cout << ns_a_d << endl;

  cout << endl << "Push" << endl;
  ns_c_i.push(5);
  cout << ns_c_i << endl;

  cout << endl << "Pop" << endl;
  ns_c_d.pop();
  cout << ns_c_d << endl;

  cout << endl << "Testing Array Stack class..." << endl;

  cout << endl << "Default constructor" << endl;
  ArrayStack<int> as_d_i;
  ArrayStack<double> as_d_d;
  cout << as_d_i << endl;
  cout << as_d_d << endl;

  cout << endl << "Parameterized constructor" << endl;
  ArrayStack<int> as_p_i(3, 3);
  ArrayStack<double> as_p_d(4.0, 4.4);
  cout << as_p_i << endl;
  cout << as_p_d << endl;

  cout << endl << "Copy constructor" << endl;
  ArrayStack<int> as_c_i(as_p_i);
  ArrayStack<double> as_c_d(as_p_d);
  cout << as_c_i << endl;
  cout << as_c_d << endl;

  cout << endl << "Assignment operator overload" << endl;
  ArrayStack<int> as_a_i;
  ArrayStack<double> as_a_d;
  as_a_i = as_p_i;
  as_a_d = as_p_d;
  cout << as_a_i << endl;
  cout << as_a_d << endl;

  cout << endl << "Push" << endl;
  as_c_i.push(5);
  cout << as_c_i << endl;

  cout << endl << "Pop" << endl;
  as_c_d.pop();
  cout << as_c_d << endl;

  return 0;
}