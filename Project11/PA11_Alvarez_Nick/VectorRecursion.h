//VectorRecursion header file with implementations, created by Nick Alvarez, 8 May 2019

#include <vector>
#include <iostream>
using namespace std;

//Vector swap implementation
template <class T>
void vector_swap(std::vector<T> & v, int a, int b)
{
  T temp;
  temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

//Bubble sort implementation
template <class T>
void vector_resort(std::vector<T> & v, size_t h)
{
  if (h==1) //If there is one element, nothing to sort
  {
    return;
  }

  //Runs through elements and compares them all
  for (int i=0; i<h-1; i++)
  {
    if (v[i] > v[i+1])
    {
      vector_swap(v, i, i+1);
    }
  }
  vector_resort(v, h-1);
}
/*
//Quicksort partition implementation
template <class T>
int vector_partition(std::vector<T> & v, int l, int h)
{
  cout << " Me" << endl;
  int pivot = v[h];  // selecting last element as pivot
  int i = (l - 1);  // index of smaller element

  for (int j = l; j <= h - 1; j++)
  {
    // If current element is smaller than or equal to pivot
    if (v[j] <= pivot)
    {
      i++;    // increment index of smaller element
      vector_swap(v, i, j);
    }
  }
  vector_swap(v, i + 1, h);
  return (i + 1);




/*
//	cout << " Me" << endl;
  int pivot = v[l];
  int lhs = l;
  int rhs = h;
//	cout << "Dec. done" << endl;
  while (lhs!=rhs)
  {
//  	cout << "Looped\t";
    //if current element is smaller than or equal to pivot
    if (v[lhs] > v[rhs])
    {
//      cout << "Internal Swap call\t";
      vector_swap(v, lhs, rhs);
    }
    if (v[lhs] == pivot)
    {
      rhs--;
    }
    if (v[rhs] == pivot)
    {
      lhs++;
    }
  }
  return left;  while (i<j)
  {
  	while (v[i] <= pivot)
  	{
  		i++;
  	}
  	while (v[j] > pivot)
  	{
  		j--;
  	}
		if (i<j)
		{
			vector_swap(v, i, j);
		}
	}
	vector_swap(v, l, j);
	return j;*/
//  cout << endl << "External Swap call" << endl;
  //return lhs;
//}

//Quicksort implementation
/*template <class T>
void vector_resort(std::vector<T> & v, int l, int h)
{
	cout << "God ";
  if (l<h)
  {
  	cout << "Help";
    int pi = vector_partition(v, l, h);
    vector_resort(v, l, pi);
    vector_resort(v, pi+1, h);
  }
}*/

//Search implementation
template <class T>
int vector_research(std::vector<T> & v, const T & value, size_t l, size_t h)
{
  size_t mid = (l+h)/2;
  
  //Incorrect parameters
  if (l>h)
  {
    return -1;
  }
  //Pivot is less than value, so search right
  if (v[mid] < value)
  {
    return vector_research(v, value, mid+1, h);
  }
  //Pivot is more than the value, so search left
  else if (v[mid] > value)
  {
    return vector_research(v, value, l, mid-1);
  }

  //Pivot is the value (base case)
  return mid;
}
