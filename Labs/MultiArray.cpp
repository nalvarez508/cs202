#include <iostream>

#include "MultiArray.h"

MultiArray::MultiArray(size_t size, float val)
{ 
  float ** storage;
  m_array = storage;
  storage = new float* [size];
  if (storage)
  {
  	  for (int i=0; i<size; i++)
	  {
	  	  storage[i] = {val};
      }
  }
}

MultiArray::~MultiArray()
{
  delete[] storage;
}

std::ostream & operator<<(std::ostream & os, const MultiArray & m){ 
  for (size_t i=0; i<m.m_size; ++i){
    os << m.m_array[i] << " ";  
  }
  os << std::endl;
  return os; 
}

