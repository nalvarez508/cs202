//Source file for ArrayQueue, created by Nick Alvarez

#include "ArrayQueue.h"
#include <iostream>

using namespace std;

//Default
ArrayQueue::ArrayQueue() :
  m_front(0),
  m_back(0),
  m_size(0)
{

}

//Parameterized
ArrayQueue::ArrayQueue(size_t count, const DataType & value) :
  m_front(0),
  m_back(0),
  m_size(0)
{
  for (int i=0; i<count; i++)
  {
    push(value);
  }
}

//Copy
ArrayQueue::ArrayQueue(const ArrayQueue & other) :
  m_front(other.m_front),
  m_back(other.m_back),
  m_size(0)
{
  for (int i=0; i<other.m_size; i++)
  {
    push(other.m_array[other.m_front + i]);
  }
}

//Destructor
ArrayQueue::~ArrayQueue()
{
//Nothing needs to be done
}

//Assignment operator overload
ArrayQueue & ArrayQueue::operator=(const ArrayQueue & rhs)
{
  if (this != &rhs)
  {
    //Empty left hand side element
    clear();
    //Assign new values
    m_front = rhs.m_front;
    m_back = rhs.m_back;
    m_size = 0;

    //New values
    for (int i=0; i<rhs.m_size; i++)
    {
      push(rhs.m_array[rhs.m_front + i]);
    }
  }
  return *this;
}

//Returns pointer to front of queue
DataType & ArrayQueue::front()
{
  return m_array[m_front];
}

//Retruns pointer to front of queue, read-only
const DataType & ArrayQueue::front() const
{
  return m_array[m_front];
}

//Returns pointer to end of queue
DataType & ArrayQueue::back()
{
  return m_array[m_back];
}

//Returns pointer to end of queue, read only
const DataType & ArrayQueue::back() const
{
  return m_array[m_back];
}

//Inserts an element to the end of the queue
void ArrayQueue::push(const DataType & value)
{
  if (m_size != ARRAY_MAX)
  {
    //Is the queue empty?
    if (!empty())
    {
      m_back = (m_back + 1) % ARRAY_MAX;
    }
    m_array[m_back] = value;
    m_size++;
  }
}

//Removes element from the front of the queue
void ArrayQueue::pop()
{
  if (!empty())
  {
    m_front = (m_front + 1) % ARRAY_MAX;
    m_size--;
  }
}

//Returns size of array
size_t ArrayQueue::size() const
{
  return m_size;
}

//Checks if array is empty
bool ArrayQueue::empty() const
{
  if (m_size)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//Checks if queue is full
bool ArrayQueue::full() const
{
  if (m_size == ARRAY_MAX)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Clears the queue, does not free memory
void ArrayQueue::clear()
{
  m_front = 0;
  m_back = 0;
  m_size = 0;
}

//Sends array elements to os
void ArrayQueue::serialize(ostream & os) const
{
  for (int i=0; i<m_size; i++)
  {
    os << i << "- " << m_array[m_front + i] << endl;
  }
}

//PC Load Letter? What does that mean?
ostream & operator<<(ostream & os, const ArrayQueue & arrayQueue)
{
  arrayQueue.serialize(os);
  return os;
}