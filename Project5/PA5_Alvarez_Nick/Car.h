#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle
{
  friend std::ostream & operator<<(std::ostream & os, Car & c);
public:
  //Default
  Car();
  //Parameterized
  Car(char * plates, int vin, float * lla);
  //Copy
  Car(const Car & other);
  //Destructor
  ~Car();

  //Methods
  Car& operator=(const Car & other);
  void drive(int throttle);
  void move(float * lla);

  //Get, set
  int getThrottle() const;
  void setThrottle(int throttle);
  const char * getPlates();
  void setPlates(const char * plates);

private:
  int m_throttle;
  char m_plates[256];
};

#endif
