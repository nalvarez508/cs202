// A signature Nick Alvarez program, produced for CS202 Project 3, due February 13, 2019
/* This program will take a file containing three rental car agencies,
estimate rental costs, find the most expensive car, and print available
cars to a file.*/

#include <iostream>
#include <fstream>
#include "RentalCar.h"
#include "RentalAgency.h"
using namespace std;

class RentalCar
{
public:
  get;
private:
  int m_year;
  char m_make[256];
  char m_model[256];
  float m_price;
  bool m_available;
};

struct RentalAgency
{
  char name[256];
  int zipcode[5];
  RentalCar inventory[5];
};

//Function definitions//

// counts characters in str array until a NULL-character '\0' is found, then it returns that number excluding the '\0' one
// the return type size_t represents an unsigned integral number large enough to contain the maximum possible number of a storage size that can appear on a target architecture
size_t myStringLength(const char * str);

// returns 0 when the C-strings match, i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
// returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
// returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char * str1, const char * str2);

// copies characters from source to destination array until a NULL-character '\0' is found in source, then it NULL-terminates destination too
// returns a pointer to the destination array
char * myStringCopy(char * destination, const char * source);

// appends the content of source to the destination array
// this means that the NULL-terminator of destination is overwritten by the first character of source and a NULL-character '\0' is appended at the end of the concatenated Cstring in destination
// returns a pointer to the destination array
char * myStringCat(char * destination, const char * source);

/*Prints menu to terminal*/
void printMenu();

/*Asks user for input file*/
void getFile(RentalAgency * agn, RentalCar * c);

/*Prints array to terminal*/
void printCarData2Term(RentalAgency * agn, RentalCar * c);

/*Prints array to file*/
void printAvailableCars2File(RentalAgency * agn, RentalCar * c);

/*Sorts cars by ascending price*/
//void sortCars(RentalCar * arr);

/*Asks user how many days desired to rent, which agency, and which car, and shows available cars and price*/
void days2Rent(RentalAgency * agn, RentalCar * c);

/*Finds the most expensive car*/
void car2Rent(RentalAgency * agn, RentalCar * c);

int main()
{
  int menuInput=0;
  RentalAgency agencies[3];
  RentalAgency * agency = agencies;
  RentalCar * cars = agency -> inventory;

  do
  {
    printMenu();
    cout << "Select your option: ";
    cin >> menuInput;
    switch (menuInput)
    {
      case 1:
      {
        getFile(agency, cars);
        break;
      }
      case 2:
      {
        printCarData2Term(agency, cars);
        break;
      }
      case 3:
      {
        days2Rent(agency, cars);
        break;
      }
      case 4:
      {
        car2rent(agency, cars);
        break;
      }
      case 5:
      {
        printAvailableCars2File(agency, cars);
        break;
      }
      case 6:
      {
        break;
      }
      default:
      {
        cout << "Please enter an option between 1 and 6." << endl;
        break;
      }
    }
  } while(menuInput!=6);

  return 0;
}

//Functions//
size_t myStringLength(const char * str)
{
  int size = 0;
  for (str; *str!='\0'; str++)
    size++;
  return size;
}
int myStringCompare(const char * str1, const char * str2)
{
  int str1length = myStringLength(str1);
  int str2length = myStringLength(str2);

  char str3[str1length];
  char str4[str2length];
  int x=0;
  for (x=0; x<str1length; x++)
  {
    str3[x]=toupper(*str1);
    str1++;
  }
  for (x=0; x<str2length; x++)
  {
    str4[x] = toupper(*str2);
    str2++;
  }

  str2=&str2[0];
  int i=0;
  int length=0;
  if (str1length>str2length)
    length=str1length;
  else if (str2length>str1length)
    length=str2length;
  else
    length=str1length;
  bool breaker=0;
  for (i=0; i<length; i++)
  {
  //  printf("Iteration %d\n", i);
    if (str3[i]!=str4[i])
    {
      //printf("They are not equal.\n");
      if (str3[i]>str4[i])
      {
      //  printf("String 2 is less.\n");
        breaker = 1;
        return -1;
      }
      else if (str3[i]<str4[i])
      {
      //  printf("String 1 is less.\n");
        breaker = 1;
        return 1;
      }
    }
  }
  if (breaker==0)
    return 0;
}
char * myStringCopy(char * destination, const char * source)
{
  *destination=*source;
  return destination;
}
char * myStringCat(char * destination, const char * source)
{
  char *c3, *c4;
  *c3=*source;
  c4=destination;
  c3=&c3[0];
  c4=&c4[myStringLength(destination)];
  int i=1;
  while (*c3!='\0')
  {
  //  printf("%s, %s\n", c1,c2);
    *c4=*c3;
  //  printf("%s, %s\t\t%d\n", c1,c2, i++);
    c3++;
    c4++;
  }
  return destination;
}

void printMenu()
{
  cout << "1) Choose input file\n2) Print data to terminal\n3) Estimate car rental cost\n4) Most expensive car\n5) Print available cars\n6) Exit\n";
}
void getFile(RentalAgency * agn, RentalCar * c)
{
  int i,j,k;
  char userInFile[30];
  cout << "Enter input filename: ";
  cin >> userInFile;
  ifstream inFile;
  inFile.open(userInFile);

  //Scans car information into array
  for (i=0; i<3; i++, agn++)
  {
    inFile >> agn.name;
    int zipcodeTemp = 0;
    inFile >> zipcodeTemp;
    
    agn.zipcode+=5;
    for (j=0; j<5; j++)
    {
        agn.zipcode << (zipcodeTemp % 10)
        zipcodeTemp=/10;
        agn.zipcode++;
    }
    
    for (k=0; k<5; k++, c++)
    {
      inFile >> c.setYear() >> c.setMake() >> c.setModel() >> c.setPrice() >> c.setAvailable();
    }
    c-=5;
  }
  
  agn-=3;
  inFile.close();
}
void printCarData2Term(RentalAgency * agn, RentalCar * c)
{
  int i,j,k;
  cout << endl;
  for (i=0; i<3; i++, agn++)
  {
      cout << endl << agn.name << " ";
      for (j=0; j<5; j++, agn.zipcode++)
      {
          cout << agn.zipcode;
      }
      cout << endl;
      for (k=0; k<5; k++, c++)
      {
        //cout << endl << c.year << " " << c.make << " " << c.model << ", $" << c.price << " per day, Available: " << boolalpha << c.available << endl;
        c.printData();
      }
      c-=5;
  }
  cout << endl;
  agn-=3;
}
void printAvailableCars2File(RentalAgency * agn, RentalCar * c)
{
  int i,j,k;
  char userOutFile[30];
  cout << "Enter output filename: ";
  cin >> userOutFile;
  ofstream outFile;
  outFile.open(userOutFile);

  for (i=0; i<3; i++, agn++)
  {
      outFile << agn.name << " ";
      for (j=0; j<5; j++, agn.zipcode++)
      {
          outFile << (*agn).zipcode;
      }
      outFile << endl;
      for (k=0; k<5; k++, c++)
      {
          if (c.getAvailable())
          {
            outFile << endl << c.getYear() << " " << c.getMake() << " " << c.getModel() << ", $" << c.getPrice() << " per day, Available: " << boolalpha << c.getAvailable() << endl;
          }
      }
      outFile << endl;
      c-=5;
  }
  outFile << endl;
  agn-=3;

  outFile.close();
}
void days2Rent(RentalAgency * agn, RentalCar * c) //Asks for agency, cars, days
{
 // sortCars(arr);
  int days=0, agnIndex=0, cIndex=0;
  float totalCost=0;
  cout << "Agency index (0-2): ";
  cin >> agnIndex;
  cout << "Car index (0-4): ";
  cin >> cIndex;
  cout << "Days to rent: ";
  cin >> days;
  cout << endl;

  agn+=agnIndex;
  c+=cIndex;
  cout << "Total cost for " << c.getYear() << " " << c.getMake() << " " << c.getModel() << "is $" << c.estimateCost(days) << endl << endl;

}
void car2Rent(RentalAgency * agn, RentalCar * c) //Finds most expensive car
{
    int i,j, agnIndex=0,cIndex=0;
    float maxPrice=0;
    for (i=0; i<3; i++, agn++)
    {
        for (j=0; j<5; j++, c++)
        {
            if (c.getPrice() > maxPrice)
            {
                maxPrice = c.price;
                agnIndex = i;
                cIndex = j;
            }
            c-=5;
        }
    }
    agn+=agnIndex;
    c+=cIndex;
    cout << "The most expensive car is a " << c.getYear() << " " << c.getMake() << " " << c.getModel() << " costing $" << maxPrice << endl << endl;
    agn-=agnIndex;
    c-=cIndex;
}

/*void sortCars(RentalCar * arr)
{
  int i=0, j=0;
  for (i=0; i<4; i++)
  {
    for (j=0; j<4-i; j++)
    {
      if (arr[j].price > arr[j+1].price)
      {
	RentalCar tempArr;
        tempArr = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tempArr;
      }
    }
  }
}*/
