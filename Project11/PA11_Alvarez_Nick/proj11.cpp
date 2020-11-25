//Proj11 test driver, created by Nick Alvarez, 8 May 2019

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "VectorRecursion.h"

using namespace std;

int main(){

  // Vector creation
  std::vector<int> vecInt;
  
  // Vector population with input values
  std::ifstream fin("RandomData.txt");
  while(fin){
    int fin_in;
    fin >> fin_in;
    if (!fin)
      break;
    vecInt.push_back( fin_in );
  }
  int v_size = vecInt.size();

  //Vector copy
  std::vector<int> vecIntCpy(vecInt);

  // Vector indexing and output ( using operator[] or at() )
  /*for (size_t i=0; i<vecInt.size(); ++i){
    std::cout << vecInt[i] << " same as " << vecInt.at(i) << std::endl; 
  }*/
  
  // Vector indexing and output ( using iterator )
  /*for (std::vector<int>::iterator it=vecInt.begin(); it!=vecInt.end(); ++it){
    std::cout << *it << std::endl; 
  }*/


  //vecInt Tests
  cout << "Sorting..." << endl;
  //Timing
  std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
  vector_resort(vecInt, v_size);
  std::chrono::time_point<std::chrono::system_clock> t2 = std::chrono::system_clock::now();
  std::chrono::duration<double> diff_v_q = t2-t1;
  //
  cout << "Sorted! Took " << diff_v_q.count()*1000000 << "ns." << endl;

  cout << "Searching for 94..." << endl;
  //Timing
  t1 = std::chrono::system_clock::now();
  cout << "Found element 94 at index " << vector_research(vecInt, 94, 0, v_size) << "!";
  t2 = std::chrono::system_clock::now();
  std::chrono::duration<double> diff_v_s = t2-t1;
  //
  cout << " Took " << diff_v_s.count()*1000000 << "ns." << endl;

  
  //vecIntCpy Tests
  t1 = std::chrono::system_clock::now();
  sort(vecIntCpy.begin(), vecIntCpy.end());
  t2 = std::chrono::system_clock::now();
  std::chrono::duration<double> diff_vcpy_q = t2-t1;

  t1 = std::chrono::system_clock::now();
  binary_search(vecIntCpy.begin(), vecIntCpy.end(), 94);
  t2 = std::chrono::system_clock::now();
  std::chrono::duration<double> diff_vcpy_s = t2-t1;


  //Timing Results
  cout << endl << "-----------------" << endl << "Timing Comparison" << endl << "-----------------" << endl;
  cout << "Sort vecInt\t" << diff_v_q.count()*1000000 << "ns" << endl;
  cout << "Sort vecIntCpy\t" << diff_vcpy_q.count()*1000000 << "ns" << endl;
  double diff_q = diff_v_q.count() - diff_vcpy_q.count();
  cout << "std::sort wins with a difference of " << diff_q*1000000 << "ns." << endl << endl;

  cout << "Srch vecInt\t" << diff_v_s.count()*1000000 << "ns" << endl;
  cout << "Srch vecIntCpy\t" << diff_vcpy_s.count()*1000000 << "ns" << endl;
  double diff_s = diff_v_s.count() - diff_vcpy_s.count();
  cout << "std::binary_search wins with a difference of " << diff_s*1000000 << "ns." << endl << endl;


  //Print vecInt
  for (int i=0; i<v_size; i++)
  {
    cout << vecInt[i] << endl;
  }

  return 0;
}
