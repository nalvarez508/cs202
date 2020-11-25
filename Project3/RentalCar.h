#ifndef RENTALCAR_H
#define RENTALCAR_H

class RentalCar
{
public:
  RentalCar();
  RentalCar(int year, char make[], char model[], float price, bool available = 0);
  void printData() const;
  float estimateCost(int) const;
  
  int getYear() const;
  char * getMake() const;
  char * getModel() const;
  float getPrice() const;
  bool getAvailable() const;
  
  void setYear(int y);
  void setMake(char mk);
  void setModel(char md);
  void setPrice(float p);
  void setAvailable(bool a);
private:
  int m_year;
  char m_make[256];
  char m_model[256];
  float m_price;
  bool m_available;
};
#endif
