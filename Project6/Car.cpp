#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;

//Default
Car::Car() :
  m_throttle(DEFAULT_INT)
{
  cout << "Car" << ": Default-ctor" << endl;
}

//Parameterized
Car::Car(float * lla) :
	Vehicle(lla),
  m_throttle(DEFAULT_INT)
{
  cout << "Car" << ": Parameterized-ctor" << endl;
}

//Copy
Car::Car(const Car & other) :
  m_throttle(other.m_throttle)
{
  SetLLA(other.m_lla);
  cout << "Car" << ": Copy-ctor" << endl;
}

//Destructor
Car::~Car()
{
  cout << "Car" << ": Dtor" << endl;
}

//Methods
Car& Car::operator=(const Car & other)
{
  SetLLA(other.m_lla);
  setThrottle(other.m_throttle);
  cout << "Car" << ": Assignment" << endl;
  return *this;
}
void::Car::drive(int throttle)
{
  setThrottle(throttle);
}
void Car::Move(float * lla)
{
  SetLLA(lla);
  cout << "Car" << ": DRIVE to destination, with throttle @ 75" << endl;
  drive(75);
}
void Car::serialize(ostream & os)
{
  os << "Car: Throttle: " << getThrottle() << " @ [";
  for (int j=0; j<3; j++)
  {
    os << m_lla[j];
    if (j<2)
    {
      os << ", ";
    }
  }
  os << "]";
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
