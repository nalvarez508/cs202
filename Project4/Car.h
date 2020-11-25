#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <fstream>

//Constants
const char DEFAULT_OWNER = '\0';
const Sensor DEFAULT_SENSOR;

class Car
{
  friend std::istream& operator>>(std::istream & iFile, Car & cars);
  friend std::ostream& operator<<(std::ostream & os, Car & cars);

public:
  //Default
  Car();
  //Parameterized
  Car(int year=DEFAULT_INT, const char * make=DEFAULT_OWNER, const char * model=DEFAULT_OWNER, float baseprice=DEFAULT_FLOAT, bool available = 0, Sensor * sensors=DEFAULT_SENSOR, const char * owner=DEFAULT_OWNER);
  //Copy
  Car(const Car & other);

  //Methods
  void updatePrice();
  void print() const;
  float estimateCost(int days) const;
  //Car& operator+(Sensor * sensors);
  //Car& operator+(Car * owner, Car available);
  int & operator[](const int index);

  //Get, set
  int getYear() const;
  void setYear(int year);
  char * getMake() const;
  void setMake(const char * make);
  char * getModel() const;
  void setModel(const char * model);
  char * getOwner() const;
  void setOwner(const char * owner);
  float getBasePrice() const;
  void setBasePrice(float baseprice);
  float getFinalPrice() const;
  bool getAvailable() const;
  void setAvailable(bool available);

private:
  int m_year;
  char m_make[256];
  char m_model[256];
  char m_owner[256];
  float m_baseprice;
  float m_finalprice;
  bool m_available;
  Sensor m_sensors[3];
};
#endif
