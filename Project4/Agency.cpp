#include <iostream>
#include <fstream>
#include "Agency.h"
#include "MainFunctions.h"
using namespace std

Agency::Agency(const char * name, int zipcode) :
  m_zipcode(DEFAULT_INT)
{
  setName(DEFAULT_NAME);
}

//Methods
void Agency::readAllData(istream & file)
{
  file >> *this;
}
void Agency::printAllData()
{
  cout << *this;
}
void Agency::printAvailableCars(Car c)
{
  for (int j=0; j<5; j++)
  {
    if (c.getAvailable())
    {
      cout << (*this).m_inventory[j];
    }
  }
}
int & Agency::operator[](const int index)
{
  return m_inventory[index];
}
istream& operator>>(istream & iFile, Agency & agn)
{
  iFile >> agn.m_name >> agn.m_zipcode;

  for (int i=0; i<5; i++)
  {
    iFile >> agn.m_inventory[i];
  }
  return iFile;
}
ostream& operator<<(ostream & os, Agency & agn)
{
  os << agn.m_name << " " << agn.m_zipcode << endl;

  for (int i=0; i<5; i++)
  {
    os << agn.m_inventory[i];
  }
  return os;
}

//Get, set
char * Agency::getName() const
{
  return m_name;
}
void Agency::setName(const char name[])
{
  myStringCopy(m_name, name);
}
int Agency::getZipcode()
{
  return m_zipcode;
}
void Agency::setZipcode(int zipcode)
{
  m_zipcode = zipcode;
}
