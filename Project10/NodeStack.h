//Header and source file for NodeStack, created by Nick Alvarez
//Must be done this way as class is templated

#ifndef NODESTACK_H
#define NODESTACK_H

#include <iostream>

template <class T>
class NodeStack;
template <class T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack);

template <class T>
class Node{

  friend class NodeStack<T>;  //allows direct accessing of link and data from class NodeStack

  public:
    Node() :
	  m_next( NULL ),
    m_data(T())
	{
	}
	Node(const T & data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	
    T & data(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<T &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const T & data() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node * m_next; 						
    T m_data;
};

template <class T>
class NodeStack {
  friend std::ostream & operator<< <> (std::ostream & os, const NodeStack<T> & nodeStack);

  public:
    //Default
    NodeStack() :
      m_top(NULL)
    {
    }
    //Parameterized
    NodeStack(size_t count, const T & value) :
      m_top(NULL)
    {
      for (int i=0; i<count; i++)
      {
        push(value);
      }
    }
    //Copy
    NodeStack(const NodeStack & other) :
      m_top(NULL)
    {
      Node<T> * curr = NULL;
      size_t s = other.size();

      for (int i=s; i>0; i--)
      {
        curr = other.m_top;
        for (int j=0; j<i-1; j++)
        {
          curr = curr->m_next;
        }
        push(curr->data());
      }
    }
    //Destructor
    ~NodeStack()
    {
      clear();
    }
    //Assignment operator overload
    NodeStack & operator=(const NodeStack & rhs)
    {
      if (this != &rhs)
      {
        clear(); //Clears out calling element
        Node<T> * curr = NULL;
        m_top = NULL;
        size_t s = rhs.size();

        for (int i=s; i>0; i--)
        {
          curr = rhs.m_top;
          for (int j=0; j<i-1; j++)
          {
            curr = curr->m_next;
          }
          push(curr->data());
        }
      }
      return *this;
    }
    //Returns a pointer to top element of stack
    T & top()
    {
      return m_top->data();
    }
    //Returns a pointer to top element of stack, read-only
    const T & top() const
    {
      return m_top->data();
    }
    //Inserts element at top of stack
    void push(const T & value)
    {
      if (empty())
      {
        m_top = new Node<T>(value);
      }
      else
      {
        m_top = new Node<T>(value, m_top);
      }
    }
    //Removes an element from the top of the stack
    void pop()
    {
      if (empty() == 0)
      {
        Node<T> * temp = m_top;
        m_top = m_top->m_next; //Traversal!
        delete temp;
      }
    }
    //Returns size of the node stack
    size_t size() const
    {
      Node<T> * curr = m_top;
      size_t s = 0;
      for (; curr != NULL; s++)
      {
        curr = curr->m_next;
      }
      return s;
    }
    //Is the stack empty?
    bool empty() const
    {
      if (m_top == NULL)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    //Is the stack full?
    bool full() const
    {
      return 0;
    }
    //Clears the stack and frees memory
    void clear()
    {
      Node<T> * curr = m_top;
      while (curr != NULL)
      {
        pop();
        curr = curr->m_next;
      }
    }
    //Sends contents of stack to os
    void serialize(std::ostream & os) const
    {
      Node<T> * curr = m_top;
      size_t s = size()-1;
      for (; curr != NULL; s--)
      {
        os << s << "- " << curr->data() << endl;
        curr = curr->m_next;
      }
    }

  private:
    Node<T> *m_top;
};

//Insertion operator overload
template <class T>
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack)
{
  nodeStack.serialize(os);
  return os;
}
#endif