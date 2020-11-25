#include "ArrayList.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream & os, const ArrayList & arrayList)
{
  for (int x=0; x<arrayList.size(); x++)
  {
    os << x << "- " << arrayList.m_array[x] << endl;
/*    if (x != arrayList.size()-1)
    {
      os << endl;
    }*/
  }
  return os;
}

//Default
ArrayList::ArrayList() :
  m_array(NULL),
  m_size(0),
  m_maxsize(0)
{
}

//Parameterized
ArrayList::ArrayList(size_t count, const DataType & value) :
  m_size(count),
  m_maxsize(count)
{
  m_array = new DataType[count];
  for (int x=0; x<count; x++)
  {
    m_array[x] = value;
  }
}

//Copy
ArrayList::ArrayList(const ArrayList & other) :
  m_size(other.m_size),
  m_maxsize(other.m_maxsize)
{
  m_array = new DataType[other.m_size];
  for (int x=0; x<m_size; x++)
  {
    m_array[x] = other.m_array[x];
  }
}

//Destructor
ArrayList::~ArrayList()
{
  delete [] m_array;
}

//Assigns new value to calling ArrayList object, an exact copy of the rhs object
ArrayList& ArrayList::operator=(const ArrayList & rhs)
{
  if (this != &rhs)
  {
    m_size = rhs.m_size;
    m_maxsize = rhs.m_maxsize;
    delete [] m_array;
    m_array = rhs.m_array;
  }
  return *this;
}

//Returns a pointer to the first valid element of m_array
DataType * ArrayList::front()
{
  for (int x=0; x<m_size; x++)
  {
    if (!empty())
    {
      return &m_array[x];
    }
  }
  return NULL;
}

//Returns a pointer to the last valid element of m_array
DataType * ArrayList::back()
{
  for (int x=m_size; x>0; x--)
  {
    if (!empty())
    {
      return &m_array[x];
    }
  }
  return NULL;
}

//Returns a pointer to an element of m_array that is equal to the specified value
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start)
{
  previous = NULL; //If search fails, this will be the default
/*  if (start != NULL)
  {
    for (int x=; x<m_size; x++)
    {
      if (m_array[x] && m_array[x] == target)
      {
        if (x != 0)
        {
          //Sets link to previous element
          previous = &m_array[x-1];
        }
        return &m_array[x]
      }
    }
  }

  }*/
  
  for (int x=0; x<m_size; x++)
  {
    if (m_array[x] == target)
    {
      if (x != 0)
      {
        //Sets link to previous element
        previous = &m_array[x-1];
      }
      return &m_array[x];
    }
  }
  return NULL;
}

//Inserts data after target element and returns a pointer to it
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value)
{

  /*find(target, value)*/
}

//Inserts data before target element and returns a pointer to it
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value)
{
/*  for (int i=0; i<m_size; i++)
  {
    if (m_array[i] == target)
    {
      m_size++
    }
  }
  m_size++;
  if (m_size > m_maxsize)
  {
    resize(m_size);
  }
  if */
}

//Finds element and deletes it
DataType * ArrayList::erase(const DataType & target)
{
  DataType * previous = NULL;
  for (int x=0; x<m_size; x++)
  {
    if (m_array[x] == target)
    {
      if (x != 0)
      {
        //Sets link to previous element
        previous = &m_array[x-1];
      }
      delete [] m_array;
    }
  }
  return NULL;
}

//Access DataType object at specific position
DataType & ArrayList::operator[](size_t position)
{
  return m_array[position];
}

//Returns size of the current list
size_t ArrayList::size() const
{
  return m_size;
}

//Checks if list is empty
bool ArrayList::empty() const
{
  if (m_array == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Clears entire list contents
void ArrayList::clear()
{
  delete [] m_array;
  m_array = NULL;
}

//Deallocates memory of m_array and allocates size_t elements
void ArrayList::resize(size_t count)
{
  m_maxsize = count;
  DataType * temp = m_array;
  m_array = NULL;
  m_array = new DataType[count];
  for (size_t x = 0; x < count; x++)
  {
    m_array[x] = temp[x];
  }
}
