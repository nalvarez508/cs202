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
  Vehicle(int vin, float * lla);
  //Copy
  Vehicle(const Vehicle & other);
  //Destructor
  ~Vehicle();

  //Methods
  Vehicle& operator=(const Vehicle & other);
  void move(float * lla);

  //Get, set
  float * getLLA();
  void setLLA(const float * lla);
  const int getVin();
  static int setVin();
  static int getIdgen();

protected:
  float m_lla[3];
  const int m_vin;
private:
  static int s_idgen;
};

#endif
