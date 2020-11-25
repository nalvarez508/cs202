#include <iostream>
#include "RentalCar.h"

RentalCar::RentalCar(int year = 0, char make[256] = " ", char[256] = " ", float price = 0, bool available = 0)
{
    m_year = year;
    m_make = make;
    m_model = model;
    m_price = price;
    m_available = available;
}

void RentalCar::printData() const
{
    cout << getYear() << " " << getMake() << " " << getModel() << ", $" << getPrice() << " per day, Available: " << boolalpha << getAvailable() << endl;
}
float RentalCar::estimateCost(int days) const
{
    float totalPrice = days*getPrice();
    return totalPrice;
}

int RentalCar::getYear() const
{
    return m_year;
}
char * RentalCar::getMake() const
{
    return m_make;
}
char * RentalCar::getModel() const
{
    return m_model;
}
float RentalCar::getPrice() const
{
    return m_price;
}
bool RentalCar::getAvailable() const
{
    return m_available;
}

void RentalCar::setYear(int y)
{
    m_year = y;
}
void RentalCar::setMake(char mk)
{
    m_make = *mk;
}
void RentalCar::setModel(char md)
{
    m_model = *md;
}
void RentalCar::setPrice(float p)
{
    m_price = p;
}
void RentalCar::setAvailable(bool a)
{
    m_available = a;
}
