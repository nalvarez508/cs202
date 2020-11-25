#ifndef RENTALAGENCY_H
#define RENTALAGENCY_H

struct RentalAgency
{
  char name[256];
  int zipcode[5];
  RentalCar inventory[5];
};
#endif
