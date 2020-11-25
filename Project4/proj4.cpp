// A signature Nick Alvarez program, produced for CS202 Project 4, due February 27, 2019
/* This program will take a file containing one rental car agency,
output total number of sensors, find the most expensive car, and print available
cars to the terminal.*/

#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "Car.h"
#include "Agency.h"
#include "MainFunctions.h"
using namespace std;

int main()
{
  int menuInput=0;
  Agency agn;
  Sensor sensor_list[4];
  Car car_list[5];

  do
  {
    printMenu();
    cout << "Select your option: ";
    cin >> menuInput;
    switch (menuInput)
    {
      case 1:
      {
        getFile(agn);
        break;
      }
      case 2:
      {
        printCarData2Term(agn);
        break;
      }
      case 3:
      {
        printTotalSensors(&sensor_list);
        break;
      }
      case 4:
      {
        car2Rent(&car_list);
        break;
      }
      case 5:
      {
        break;
      }
      default:
      {
        cout << "Please enter an option between 1 and 5." << endl;
        break;
      }
    }
  } while(menuInput!=5);

  return 0;
}
