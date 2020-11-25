#include "NodeList.h"
#include <iostream>

using namespace std;

//Default
NodeList::NodeList() :
  m_head(NULL)
{
}

//Parameterized
NodeList::NodeList(size_t count, const DataType & value)
{
  Node * curr = NULL;
  Node * next = NULL;

  for (; count>0; count--)
  {
    if (!next)
    {
      next = new Node(value);
    }
    else
    {
      curr = new Node(value, next);
      next = curr;
    }
  }
  m_head = curr;
}

//Copy
NodeList::NodeList(const NodeList & other)
{
  Node * newCurr = other.m_head;
  Node * oldCurr = NULL;
  Node * newNode;

  while (newCurr)
  {
    newNode = new Node(*newCurr);
    if (!oldCurr)
    {
      m_head = newNode;
      oldCurr = m_head;
    }
    else
    {
      oldCurr -> m_next = newNode;
      oldCurr = newNode;
    }
    newCurr = newCurr -> m_next;
  }
}

//Destructor
NodeList::~NodeList()
{
  Node *curr = m_head;
  Node *nextOne;
  if (m_head!=NULL)
  {
    do
    {
      nextOne = curr -> m_next;
      delete curr;
    } while (curr = nextOne);
  }
  else
  {
  }
}

//Assigns new value to calling object
NodeList& NodeList::operator=(const NodeList & rhs)
{
  if (this != &rhs)
  {
    m_head = rhs.m_head;
  }
}

//Returns pointer to the first element
Node * NodeList::front()
{
  return m_head;
}

//Returns pointer to the last element
Node * NodeList::back()
{
  Node * curr = m_head;
  //Traverses list till curr == NULL
  while (curr -> m_next)
  {
    curr = curr -> m_next;
  }
  return curr;
}

//Returns pointer to first matching element
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start)
{
  Node * found = NULL;
  Node * curr = m_head;
  Node * prevOne = NULL;
  
  while (curr)
  {
    if (curr -> data() == target)
    {
      found = curr;
      previous = prevOne;
      break;
    }
    //Moves to next
    prevOne = curr;
    curr = curr -> m_next;
  }
  return found;
}

//Finds matching element and inserts node after it
Node * NodeList::insertAfter(const DataType & target, const DataType & value)
{
  Node * prevOne = NULL;
  Node * found = NULL;
  Node * newNode = NULL;
  found = find(target, prevOne);

  if (found!=NULL)
  {
    //Last element in list
    if (found->m_next == NULL)
    {
      newNode = new Node(value);
      found -> m_next = newNode;
    }
    //Somewhere in middle of list
    else
    {
      newNode = new Node(value, found -> m_next);
      found -> m_next = newNode;
    }
  }
  return newNode;
}

//Finds matching element and inserts node before it
Node * NodeList::insertBefore(const DataType & target, const DataType & value)
{
  Node * prevOne = NULL;
  Node * found = NULL;
  Node * newNode = NULL;
  found = find(target, prevOne);

  if (found != NULL)
  {
    //Last element in list
    if (prevOne == NULL)
    {
      newNode = new Node(value, found);
      m_head = newNode;
    }
    //Somewhere in middle of list
    else
    {
      newNode = new Node(value, found);
      prevOne -> m_next = newNode;
    }
  }
  return newNode;
}

//Finds matching element and removes it
Node * NodeList::erase(const DataType & target)
{
  Node * prevOne = NULL;
  Node * found = NULL;
  Node * nextOne = NULL;
  Node * temp = NULL;
  found = find(target, prevOne);

  if (found != NULL)
  {
    if (prevOne == NULL)
    {
      temp = m_head;
      nextOne = m_head -> m_next;
      m_head = nextOne;
    }
    else
    {
      temp = found;
      nextOne = found -> m_next;
      prevOne -> m_next = nextOne;
    }
    delete temp;
  }
  return nextOne;
}

//Accesses specific element within list
DataType & NodeList::operator[](size_t position)
{
  Node * curr = m_head;
  for (; position > 0; position--)
  {
    curr = curr -> m_next;
    if (!curr)
    {
      break;
    }
  }
  return curr->data();
}

//Accesses specific element within list, but saferer
const DataType & NodeList::operator[](size_t position) const
{
  Node * curr = m_head;
  for (; position > 0; position--)
  {
    curr = curr -> m_next;
    if (!curr)
    {
      break;
    }
  }
  return curr -> data();
}

//Finds size of list
size_t NodeList::size() const
{
  Node * curr = m_head;
  size_t x = 0;
  while (curr != NULL)
  {
    x++;
    curr = curr -> m_next;
  }
  return x;
}

//Is the list empty?
bool NodeList::empty() const
{
  if (m_head == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

//Nukes the list
void NodeList::clear()
{
  Node * curr = m_head;
  Node * nextOne = NULL;
  m_head = NULL;

  while (curr != NULL)
  {
    nextOne = curr -> m_next;
    delete curr;
    curr = nextOne;
  }
}

//Insertion operator overload
ostream & operator<<(ostream & os, const NodeList & nodeList)
{
  size_t nodeSize = nodeList.size();
  for (int i=0; i < nodeSize; i++)
  {
    os << i << "- " << nodeList[i] << endl;
  }
  return os;
}
