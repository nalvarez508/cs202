#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

//Default
Vehicle::Vehicle()
{
  cout << "Vehicle" << ": Default-ctor" << endl;
}

//Parameterized
Vehicle::Vehicle(float * lla)
{
  SetLLA(lla);
  cout << "Vehicle" << ": Parameterized-ctor" << endl;
}

//Copy
Vehicle::Vehicle(const Vehicle & other)
{
  SetLLA(other.m_lla);
  cout << "Vehicle" << ": Copy-ctor" << endl;
}

//Destructor
Vehicle::~Vehicle()
{
  cout << "Vehicle" << ": Dtor" << endl;
}

//Methods
Vehicle& Vehicle::operator=(const Vehicle & other)
{
  SetLLA(other.m_lla);
  cout << "Vehicle" << ": Assignment" << endl;
  return *this;
}
void Vehicle::Move(float * lla)
{
  SetLLA(lla);
  cout << "Vehicle" << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}
ostream& operator<<(ostream & os, Vehicle & v)
{
  v.serialize(os);
  return os;
}
void Vehicle::serialize(ostream & os)
{
  os << "Vehicle" << " @ [";
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
float * Vehicle::getLLA()
{
  return m_lla;
}
void Vehicle::SetLLA(const float * lla)
{
  for (int i=0; i<3; i++)
  {
    m_lla[i] = lla[i];
  }
}
