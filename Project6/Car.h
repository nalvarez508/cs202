#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle
{
public:
  //Default
  Car();
  //Parameterized
  Car(float * lla);
  //Copy
  Car(const Car & other);
  //Destructor
  virtual ~Car();

  //Methods
  Car& operator=(const Car & other);
  void drive(int throttle);
  virtual void Move(float * lla);

  //Get, set
  int getThrottle() const;
  void setThrottle(int throttle);

private:
  int m_throttle;
  virtual void serialize(std::ostream & os);
};

#endif
