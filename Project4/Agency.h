#ifndef AGENCY_H
#define AGENCY_H
#include <iostream>
#include <fstream>

//Constants
const char DEFAULT_NAME = '\0';

class Agency
{
  friend std::istream& operator>>(std::istream & iFile, Agency & agn);
  friend std::ostream& operator<<(std::ostream & os, Agency & agn);
public:
  //Default
  Agency();

  //Methods
  void readAllData(std::istream file);
  void printAllData();
  void printAvailableCars(Car c);
  int & operator[](const int index);

  //Get, set
  char * getName() const;
  void setName(const char name[]);
  int getZipcode();
  void setZipcode(int zipcode);

private:
  char m_name[256];
  int m_zipcode;
  Car m_inventory[5];
};
#endif
