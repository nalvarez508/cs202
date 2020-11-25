#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

//Default
Car::Car() :
  m_throttle(DEFAULT_INT)
//  m_vin(getIdgen())
{
  cout << "Car #" << getVin() << ": Default-ctor" << endl;
}

//Parameterized
Car::Car(char * plates, int vin, float * lla) :
	Vehicle(vin, lla),
  m_throttle(DEFAULT_INT)
{
  setLLA(lla);
  setPlates(plates);
  cout << "Car #" << getVin() << ": Parameterized-ctor" << endl;
}

//Copy
Car::Car(const Car & other) :
//  m_vin(other.m_vin),
  m_throttle(other.m_throttle)
{
  setLLA(other.m_lla);
  setPlates(other.m_plates);
  cout << "Car #" << getVin() << ": Copy-ctor" << endl;
}

//Destructor
Car::~Car()
{
  cout << "Car #" << getVin() << ": Dtor" << endl;
}

//Methods
Car& Car::operator=(const Car & other)
{
  if ((*this).m_vin != other.m_vin)
  {
    setLLA(other.m_lla);
    setThrottle(other.m_throttle);
    setPlates(other.m_plates);
  }
  cout << "Car #" << getVin() << ": Assignment" << endl;
  return *this;
}
void::Car::drive(int throttle)
{
  setThrottle(throttle);
}
void Car::move(float * lla)
{
  setLLA(lla);
  cout << "Car #" << getVin() << ": DRIVE to destination, with throttle @ 75" << endl;
  drive(75);
}
ostream& operator<<(ostream & os, Car & c)
{
  os << "Car #" << c.getVin() << " Plates: " << c.getPlates() << ", Throttle: " << c.getThrottle() << " @ [";
  for (int j=0; j<3; j++)
  {
    os << c.m_lla[j];
    if (j<2)
    {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

//Get, set
int Car::getThrottle() const
{
  return m_throttle;
}
void Car::setThrottle(int throttle)
{
  m_throttle = throttle;
}
const char * Car::getPlates()
{
  return m_plates;
}
void Car::setPlates(const char * plates)
{
  strcpy(m_plates, plates);
}
