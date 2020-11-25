#include <iostream>
#include <cstring>
#include "SmartPtr.h"

using namespace std;

//Default
SmartPtr::SmartPtr()
{
  m_ptr = new DataType;
  m_refcount = new size_t;
  *m_refcount = 1;
  cout << "SmartPtr Default Constructor for new allocation, RefCount=" << *m_refcount << endl;
}

//Parameterized
SmartPtr::SmartPtr(DataType * data)
{
  m_refcount = new size_t;
  if (data==NULL)
  {
    *m_refcount = 0;
  }
  else
  {
    *m_refcount = 1;
  }
  m_ptr = data;
  cout << "SmartPtr Parameterized Constructor from data pointer, RefCount=" << *m_refcount << endl;
}

//Copy
SmartPtr::SmartPtr(const SmartPtr & other)
{
  if (other.m_ptr==NULL)
  {
    m_refcount = new size_t;
    *m_refcount = 0;
  }
  else
  {
    m_refcount = other.m_refcount;
    (*m_refcount)++;
  }
  m_ptr = other.m_ptr;
  cout << "SmartPtr Copy Constructor, RefCount=" << *m_refcount << endl;
}

//Destructor
SmartPtr::~SmartPtr()
{
  (*m_refcount)--;
  cout << "SmartPtr Destructor, RefCount=" << *m_refcount << std::endl;
  if (*m_refcount==0)
  {
    delete m_refcount;
    delete m_ptr;
  }
}

///////////Methods///////////

//Sets one object's pointer to another's
SmartPtr & SmartPtr::operator=(const SmartPtr & rhs)
{
  if (this != &rhs)
  {
    (*m_refcount)--;
    if (*m_refcount==0)
    {
      delete m_refcount;
      delete m_ptr;
    }
    if (rhs.m_ptr==NULL)
    {
      m_refcount = new size_t;
      *m_refcount = 0;
    }
    else
    {
      m_refcount = rhs.m_refcount;
      (*m_refcount)++;
    }
    m_ptr = rhs.m_ptr;
  }
  cout << "SmartPtr Copy Assignment, RefCount=" << *m_refcount << endl;
  return *this;
}

//Returns a dereferenced pointer
DataType & SmartPtr::operator*()
{
  return *m_ptr;
}

//Returns the pointer
DataType * SmartPtr::operator->()
{
  return m_ptr;
}
