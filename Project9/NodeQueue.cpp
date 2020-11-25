//Source file for NodeQueue, created by Nick Alvarez

#include "NodeQueue.h"
#include <iostream>

using namespace std;

//Default
NodeQueue::NodeQueue() :
  m_front(NULL),
  m_back(NULL)
{

}

//Parameterized
NodeQueue::NodeQueue(size_t size, const DataType & value) :
  m_front(NULL),
  m_back(NULL)
{
  for (int i=0; i<size; i++)
  {
    push(value);
  }
}

//Copy
NodeQueue::NodeQueue(const NodeQueue & other) :
  m_front(NULL),
  m_back(NULL)
{
  Node * curr = other.m_front;
  while (curr!=NULL)
  {
    push(curr->data());
    //When you're #traversing the list
    curr = curr->m_next;
  }
}

//Destructor
NodeQueue::~NodeQueue()
{
  Node * curr = m_front;
  Node * nextOne = NULL;

  while(curr!=NULL)
  {
    nextOne = curr->m_next;
    delete curr; //Frees memory
    curr = nextOne;
  }
}

//Assignment operator overload
NodeQueue & NodeQueue::operator=(const NodeQueue & rhs)
{
  if (this != &rhs)
  {
    //Clears left hand side
    clear();

    m_front = NULL;
    m_back = NULL;
    Node * curr = rhs.m_front;
    
    while (curr!=NULL)
    {
      push(curr->data());
      curr = curr->m_next;
    }
  }
  return *this;
}

//Returns pointer to the front of the queue
DataType & NodeQueue::front()
{
  return m_front->data();
}

//Returns pointer to the front of the queue, read only
const DataType & NodeQueue::front() const
{
  return m_front->data();
}

//Returns pointer to the end of the queue
DataType & NodeQueue::back()
{
  return m_back->data();
}

//Returns pointer to the end of the queue, read only
const DataType & NodeQueue::back() const
{
  return m_back->data();
}

//Inserts element at the back of the queue
void NodeQueue::push(const DataType & value)
{
  Node * newNode = new Node(value);
  //If list is empty, set front and back to itself
  if (empty())
  {
    m_front = newNode;
    m_back = newNode;
    break;
  }
  m_back->m_next = newNode;
  m_back = newNode;
}

//Removes an element fromt the front of the queue
void NodeQueue::pop()
{
  if (size() == 1) //Popping from queue with one element would make it empty
  {
    clear();
  }
  else if (!empty())
  {
    Node *temp = m_front;
    m_front = m_front->m_next; //Moves front down one
    delete temp;
  }
}

//Finds number of elements in queue
size_t NodeQueue::size() const
{
  Node * curr = m_front;
  for (size_t x=0; curr!=NULL; x++)
  {
    curr = curr->m_next;
  }
  return x;
}

//Checks if queue is empty
bool NodeQueue::empty() const
{
  if (m_front==NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Checks if queue is full (outdated)
bool NodeQueue::full() const
{
  return false;
}

//Clears the entirety of the queue
void NodeQueue::clear()
{
  Node * curr = m_front;
  Node * temp = NULL;

  while (curr!=NULL)
  {
    temp = curr;
    curr = curr->m_next;
    delete temp;
  }
  m_front = NULL;
  m_back = NULL;
}

//Sends contents of queue to os
void NodeQueue::serialize(ostream & os) const
{
  Node * curr = m_front;
  for (int i=0; curr!=NULL; i++)
  {
    os << i << "- " << curr->data() << endl;
    curr = curr->m_next;
  }
}

//Prints
ostream & operator<<(ostream & os, const NodeQueue & nodeQueue)
{
  nodeQueue.serialize(os);
  return os;
}