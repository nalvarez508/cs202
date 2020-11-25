//Header and source file for ArrayStack, created by Nick Alvarez
//Must be done this way as class is templated

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>

template <class T, size_t MAX_STACKSIZE = 1000>
class ArrayStack;
template <class T, size_t MAX_STACKSIZE>
std::ostream & operator<<(std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & arrayStack);

template <class T, size_t MAX_STACKSIZE>
class ArrayStack {
  friend std::ostream & operator<< <> (std::ostream & os, const ArrayStack<T,MAX_STACKSIZE> & arrayStack);

  public:
    //Default
    ArrayStack() :
      m_top(0)
    {
    }
    //Parameterized
    ArrayStack(size_t count, const T & value) :
      m_top(0)
    {
      for (int i=0; i<count; i++)
      {
        push(value);
      }
    }
    //Copy
    ArrayStack(const ArrayStack & other) :
      m_top(0)
    {
      size_t s = other.size();
      for (int i=0; i<s; i++)
      {
        push(other.m_container[i]);
      }
    }
    //Destructor
    ~ArrayStack()
    {
      //Nothing needs to be done
    }
    //Assignment operator overload
    ArrayStack & operator=(const ArrayStack & rhs)
    {
      if (this != &rhs)
      {
        clear(); //Clear calling object
        size_t s = rhs.size();
        for (int i=0; i<s; i++)
        {
          push(rhs.m_container[i]);
        }
      }
      return *this;
    }
    //Returns pointer to last inserted element of stack
    T & top()
    {
      return m_container[m_top-1];
    }
    //Returns pointer to last inserted element of stack, read-only
    const T & top() const
    {
      return m_container[m_top-1];
    }
    //Inserts at top of stack a given element
    void push(const T & value)
    {
      if (full() == 0)
      {
        m_top++;
        m_container[m_top] = value;
      }
    }
    //Removes element from top of stack
    void pop()
    {
      if (empty() == 0)
      {
        m_top--;
      }
    }
    //Returns size of array stack
    size_t size() const
    {
      return m_top;
    }
    //Is the stack empty?
    bool empty() const
    {
      if (m_top == 0)
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
      if (size() >= MAX_STACKSIZE)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
    //Removes everything from the stack, at least so we cannot find the data anymore
    void clear()
    {
      m_top = 0;
    }
    //Sends contents of stack to os
    void serialize(std::ostream & os) const
    {
      size_t s = size();
      for (int i=s-1; i>0; i--)
      {
        os << i << "- " << m_container[i] << endl;
      }
    }
  private:
    T m_container[MAX_STACKSIZE];
    size_t m_top;
};

//Insertion operator overload
std::ostream & operator<<(std::ostream & os, const ArrayStack<T,MAX_STACKSIZE> & arrayStack)
{
  arrayStack.serialize(os);
  return os;
}
#endif