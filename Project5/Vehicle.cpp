#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;

int Vehicle::s_idgen = 0;

//Default
Vehicle::Vehicle() :
	m_vin(setVin())
{
	setLLA(DEFAULT_FLOAT);
  cout << "Vehicle #" << getVin() << ": Default-ctor" << endl;
}

//Parameterized
Vehicle::Vehicle(int vin, float * lla) :
  m_vin(vin)
{
  setLLA(lla);
  cout << "Vehicle #" << getVin() << ": Parameterized-ctor" << endl;
}

//Copy
Vehicle::Vehicle(const Vehicle & other) :
	m_vin(setVin())
{
  setLLA(other.m_lla);
  cout << "Vehicle #" << getVin() << ": Copy-ctor" << endl;
}

//Destructor
Vehicle::~Vehicle()
{
  cout << "Vehicle #" << getVin() << ": Dtor" << endl;
}

//Methods
Vehicle& Vehicle::operator=(const Vehicle & other)
{
  if ((*this).getVin() != other.m_vin)
  {
  	
    setLLA(other.m_lla);
  }
  cout << "Vehicle #" << getVin() << ": Assignment" << endl;
  return *this;
}
void Vehicle::move(float * lla)
{
  setLLA(lla);
  cout << "Vehicle #" << getVin() << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}
ostream& operator<<(ostream & os, Vehicle & v)
{
  os << "Vehicle #" << v.m_vin << " @ [";
  for (int j=0; j<3; j++)
  {
    os << v.m_lla[j];
    if (j<2)
    {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

//Get, set
float * Vehicle::getLLA()
{
  return m_lla;
}
void Vehicle::setLLA(const float * lla)
{
  for (int i=0; i<3; i++)
  {
    m_lla[i] = lla[i];
  }
}
const int Vehicle::getVin()
{
  return m_vin;
}
int Vehicle::setVin()
{
	s_idgen++;
	return getIdgen();
}
int Vehicle::getIdgen()
{
  return s_idgen;
}
