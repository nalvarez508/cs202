#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

//Constants
const int DEFAULT_INT=0;
const float DEFAULT_FLOAT[3] = {0};

class Vehicle
{
  friend std::ostream & operator<<(std::ostream & os, Vehicle & v);
public:
  //Default
  Vehicle();
  //Parameterized
  Vehicle(float * lla);
  //Copy
  Vehicle(const Vehicle & other);
  //Destructor
  virtual ~Vehicle();

  //Methods
  Vehicle& operator=(const Vehicle & other);
  virtual void Move(float * lla) = 0;

  //Get, set
  float * getLLA();
  void SetLLA(const float * lla);

protected:
  float m_lla[3];
private:
  virtual void serialize(std::ostream & os);
};

#endif
