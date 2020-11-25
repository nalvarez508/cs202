#include <iostream>
#include <cstring>
#include "MyString.h"
const size_t DEFAULT_SIZE = 0;
char * DEFAULT_BUFFER = NULL;

using namespace std;

ostream& operator<<(ostream & os, const MyString & myStr)
{
  os << myStr.c_str() << endl;
}

//Default
MyString::MyString() :
  m_size(DEFAULT_SIZE),
  m_buffer(DEFAULT_BUFFER)
{
  cout << "Default constructor" << endl;
}

//Parameterized
MyString::MyString(const char * str)
{
  cout << "Parameterized constructor" << endl;
  size_t size = strlen(str);

  buffer_allocate(size);
  strcpy(m_buffer, str);
}

//Copy
MyString::MyString(const MyString & other_myStr)
{
  cout << "Copy constructor" << endl;
  buffer_allocate(other_myStr.m_size);
  strcpy(m_buffer, other_myStr.m_buffer);
}

//Destructor
MyString::~MyString()
{
  cout << "Destructor" << endl;
  buffer_deallocate();
}

///////////Methods///////////

//Returns length of string, including \0
size_t MyString::size() const
{
  cout << "Size" << endl;
  return m_size;
}
//Returns length of string
size_t MyString::length() const
{
  cout << "Length" << endl;
  return strlen(m_buffer);
}

//Returns pointer to string
const char * MyString::c_str() const
{
  cout << "C_str" << endl;
  return m_buffer;
}

//Checks if two objects' strings are the same
bool MyString::operator==(const MyString & other_myStr) const
{
  cout << "Comparison operator overload" << endl;
  if (strcmp(m_buffer, other_myStr.c_str()))
    return 1;
  else
    return 0;
}

//Sets one object's string to another's
MyString & MyString::operator=(const MyString & other_myStr)
{
  cout << "Assignment operator overload" << endl;
  if (this != &other_myStr)
  {
    if (m_size != other_myStr.m_size)
    {
      buffer_deallocate();
      size_t newStrSize = strlen(other_myStr.c_str());
      buffer_allocate(newStrSize);
    }
    strcpy(m_buffer, other_myStr.c_str());
  }
  return *this;
}

//Concatenates string
MyString MyString::operator+(const MyString & other_myStr) const
{
  cout << "Addition operator overload" << endl;
  size_t concatStr = m_size + other_myStr.m_size;
  char newStr[concatStr];
  strcpy(newStr, c_str());
  strcat(newStr, other_myStr.c_str());
  return MyString(newStr);
}

//Accesses index of string array
char & MyString::operator[](size_t index)
{
  cout << "Bracket operator overload" << endl;
  return m_buffer[index];
}

//Accesses index of string array, but better
const char & MyString::operator[](size_t index) const
{
  cout << "Bracket operator overload const qualified" << endl;
  return m_buffer[index];
}

//Dynamically allocates memory for string
void MyString::buffer_allocate(size_t size)
{
  cout << "Buffer allocate" << endl;
  m_buffer = new char [size+1];
  if (!m_buffer)
  {
    cerr << "Allocation failed" << endl;
    buffer_deallocate();
  }
  else
  {
    m_size = size+1;
  }
}

//Deallocates memory from m_buffer
void MyString::buffer_deallocate()
{
  cout << "Buffer deallocate" << endl;
  delete [] m_buffer;
  m_buffer = DEFAULT_BUFFER;
  m_size = DEFAULT_SIZE;
}
