//A signature Nick Alvarez program, created for Project 9 of CS202, due 4/24/19
//Test driver for queue classes

#include <iostream>
#include "ArrayQueue.h"
#include "DataType.h"
#include "NodeQueue.h"

using namespace std;

int main()
{
  DataType dt1(1, 1.1);
  DataType dt2(2, 2.2);

  cout << "Testing Node Queue class..." << endl;

  cout << endl << "Default constructor" << endl;
  NodeQueue nq_d;
  cout << nq_d << endl;

  cout << endl << "Parameterized constructor" << endl;
  NodeQueue nq_p(3, dt1);
  cout << nq_p << endl;

  cout << endl << "Copy constructor" << endl;
  NodeQueue nq_c(nq_p);
  cout << nq_c << endl;

  cout << endl << "Assignment operator overload" << endl;
  NodeQueue nq_a;
  nq_a = nq_p;
  cout << nq_a << endl;

  cout << endl << "Push" << endl;
  nq_c.push(dt2);
  cout << nq_c << endl;

  cout << endl << "Pop" << endl;
  nq_c.pop();
  cout << nq_c << endl;

  cout << endl << "Testing Array Queue class..." << endl;

  cout << endl << "Default constructor" << endl;
  ArrayQueue aq_d;
  cout << aq_d << endl;

  cout << endl << "Parameterized constructor" << endl;
  ArrayQueue aq_p(3, dt1);
  cout << aq_p << endl;

  cout << endl << "Copy constructor" << endl;
  ArrayQueue aq_c(aq_p);
  cout << aq_p << endl;

  cout << endl << "Assignment operator overload" << endl;
  ArrayQueue aq_a;
  aq_a = aq_p;
  cout << aq_a << endl;

  cout << endl << "Push" << endl;
  aq_c.push(dt2);
  cout << aq_c << endl;

  cout << endl << "Pop" << endl;
  aq_c.pop();
  cout << aq_c << endl;

  return 0;
}