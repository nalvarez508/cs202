#include <iostream>
#include <fstream>
#include <MainFunctions.h>
using namespace std;

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
  cout << "1) Choose input file\n2) Print data to terminal\n3) Total number of sensors\n4) Most expensive car\n5) Exit\n";
}
void getFile(Agency agn) //Used with Agency::readAllData
{
  int i,j,k;
  char userInFile[30];
  cout << "Enter input filename: ";
  cin >> userInFile;
  ifstream inFile;
  inFile.open(userInFile);
  agn.readAllData(inFile); //Need the agency?
  inFile.close();
}
void printCarData2Term(Agency agn) //Used with Agency::printAllData
{
  cout << endl;
  agn.printAllData();
  //Print agency name and zipcode
  //Print car data using its << overload and pointer
  cout << endl;
}
void printTotalSensors(Sensor s)
{
  cout << endl;
  cout << "GPS: " << s.getGPS() << endl;
  cout << "Camera: " << s.getCamera() << endl;
  cout << "Lidar: " << s.getLidar() << endl;
  cout << "Radar: " << s.getRadar() << endl;
  cout << endl;
}
//Finds the most expensive car and asks the user if they want to rent it
void car2Rent(Car c)
{
  Car * cPtr;
  cPtr = c;
    int j,cIndex=0
    char rentInput='\0';
    char nameInput[30];
    float maxPrice=0;
    for (j=0; j<5; j++, cPtr++)
    {
      if (((*cPtr).getFinalPrice() > maxPrice) && (*cPtr).getAvailable())
      {
        maxPrice = (*cPtr).getFinalPrice();
        cIndex = j;
      }
    }
    cPtr-=5;
    cPtr+=cIndex;
    cout << "The most expensive car is a " << (*cPtr).getYear() << " " << (*cPtr).getMake() << " " << (*cPtr).getModel() << " costing $" << maxPrice << endl;
    cout << "Would you like to rent it (y/n)? ";
    cin >> userInput;
    if (userInput=='y')
    {
      cout << "Enter your name: ";
      cin >> nameInput;
      (*cPtr).setAvailable(0);
      (*cPtr).setOwner(nameInput);
    }
    cPtr-=cIndex;
    cout << endl;
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
