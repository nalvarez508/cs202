// A signature Nick Alvarez program, produced for CS202 Project 3, due February 13, 2019
/* This program will take a file containing three rental car agencies,
estimate rental costs, find the most expensive car, and print available
cars to a file.*/

#include <iostream>
#include <fstream>
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
void getFile(RentalCar * arr);

/*Prints array to terminal*/
void printCarData2Term(RentalCar arr[]);

/*Prints array to file*/
void printAvailableCars2File(RentalCar arr[]);

/*Sorts cars by ascending price*/
void sortCars(RentalCar arr[]);

/*Asks user how many days desired to rent, which agency, and which car, and shows available cars and price*/
void days2Rent(RentalCar arr[]);

/*Asks user which car desired to rent and for how long*/
void car2Rent(RentalCar arr[]);

int main()
{
  int menuInput=0;

  do
  {
    printMenu();
    cout << "Select your option: ";
    cin >> menuInput;
    switch (menuInput)
    {
      case 1:
      {
        getFile(cars);
        break;
      }
      case 2:
      {
        printCarData2Term(cars);
        break;
      }
      case 3:
      {
        days2Rent();
        break;
      }
      case 4:
      {
        findExpensiveCar();
        break;
      }
      case 5:
      {
        printAvailableCars2File();
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
void getFile(RentalCar * arr)
{
  char userInFile[30];
  cout << "Enter input filename: ";
  cin >> userInFile;
  ifstream inFile;
  inFile.open(userInFile);

  //Scans car information into array
  for (int i=0; i<5; i++, arr++)
  {
    inFile >> arr.m_year >> arr.m_make >> arr.m_model >> arr.m_price >> arr.m_available;
  }

  inFile.close();
}
void printCarData2Term(RentalCar arr[])
{
  cout << endl;
  for (int i=0; i<5; i++)
  {
    cout << "[" << i << "]: " << arr[i].year << " " << arr[i].make << " " << arr[i].model << ", $" << arr[i].price << " per day, Available: " << boolalpha << arr[i].available << endl << endl;
  }
}
void printAvailableCars2File(RentalCar arr[])
{
  char userOutFile[30];
  cout << "Enter output filename: ";
  cin >> userOutFile;
  ofstream outFile;
  outFile.open(userOutFile);

  for (int i=0; i<5; i++)
  {
    outFile << arr[i].year << " " << arr[i].make << " " << arr[i].model << ", $" << arr[i].price << " per day, Available: " << boolalpha << arr[i].available << endl << endl;
  }

  outFile.close();
}
void days2Rent(RentalCar arr[])
{
  sortCars(arr);
  int days=0;
  float totalCost=0;
  cout << "Days to rent: ";
  cin >> days;
  cout << endl;

  for (int i=0; i<5; i++)
  {
    if (arr[i].available)
    {
      totalCost = arr[i].price * days;
      cout << "[" << i << "]: " << arr[i].year << " " << arr[i].make << " " << arr[i].model << ", Total Cost: $" << totalCost << endl << endl;
    }
  }
}

void sortCars(RentalCar arr[])
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
}
void car2Rent(RentalCar arr[])
{
  int carIndex=0, days=0;
  float totalCost;
  cout << "Car to rent [index]: ";
  cin >> carIndex;
  cout << "Days to rent: ";
  cin >> days;
  cout << endl;

  if (arr[carIndex].available)
  {
    arr[carIndex].available = 0;
    totalCost = arr[carIndex].price * days;
    cout << "Success! Total cost for " << days << " days is: $" << totalCost << endl << endl;
  }
  else
  {
    cout << "Warning! Car unavailable." << endl << endl;
  }
}
