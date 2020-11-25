#include <iostream>
#include "Car.h"
#include "MainFunctions.h"
#include <fstream>
using namespace std;

Car::Car() :
  m_year(DEFAULT_INT),
  m_baseprice(DEFAULT_FLOAT),
  m_available(0)
{
  setMake(DEFAULT_OWNER);
  setModel(DEFAULT_OWNER);
  setOwner(DEFAULT_OWNER);
}

//Parameterized
Car::Car(int year, const char * make, const char * model, float baseprice, bool available, const char * owner) :
  m_year(year),
  m_baseprice(baseprice),
  m_available(available)
{
  setMake(make);
  setModel(model);
  setOwner(owner);
}

//Methods
void Car::updatePrice()
{

  m_finalprice = m_baseprice
}
void Car::printData() const
{
    cout << this;
}
float Car::estimateCost(int days) const
{
    float totalPrice = days*m_finalprice;
    return totalPrice;
}
//  Car& operator+(Sensor * sensors);
//  Car& operator+(Car * owner, Car available);

int & Car::operator[](const int index)
{
  return m_sensors[index];
}
istream& operator>>(istream & iFile, Car & cars)
{
  iFile >> cars.m_year >> cars.m_make >> cars.m_model >> cars.m_baseprice;
  for (int i=0; i<4; i++)
  {
    iFile >> cars.m_sensors[i];
  }
  iFile >> cars.m_available >> cars.m_owner;
}
ostream& operator<<(ostream & os, Car & cars)
{
  os << endl;
  os << cars.m_year << " " << cars.m_make << " " << cars.m_model << ", $" << cars.m_baseprice << " per day, Sensors: {";
  for (int i=0; i<4; i++)
  {
    os << cars.m_sensors[i];
  }
  os << "}, Available: " boolalpha << cars.m_available;
  if (cars.m_available)
    os << ", Owner: " << cars.m_owner;
  os << endl;
}

int Car::getYear() const
{
    return m_year;
}
char * Car::getMake() const
{
    return m_make;
}
char * Car::getModel() const
{
    return m_model;
}
float Car::getBasePrice() const
{
    return m_baseprice;
}
float Car::getFinalPrice() const
{
  return m_finalprice
}
bool Car::getAvailable() const
{
    return m_available;
}
char * Car::getOwner() const
{
  return m_owner;
}

void Car::setYear(int y)
{
    m_year = y;
}
void Car::setMake(const char * mk)
{
    myStringCopy(m_make, mk)
}
void Car::setModel(const char * md)
{
    myStringCopy(m_model, md);
}
void Car::setBasePrice(float p)
{
    m_baseprice = p;
}
void Car::setAvailable(bool a)
{
    m_available = a;
}
void Car::setOwner(const char * o)
{
  myStringCopy(m_owner, o);
}
