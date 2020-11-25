// A signature Nick Alvarez program, produced for CS202 Project 1, due January 30, 2019
/* This program will take in a list of 10 names from a file, determine alphabetical order, sort them by length, and write the sorted length to a file.*/

#include <iostream>
#include <fstream>
using namespace std;

const int row = 10;
const int col = 11;

//Function definitions//

/*copies characters from source to destination until a NULL-character '\0' is found in source, then it NULL-terminates destination too, and returns*/
void myStringCopy(char destination [], const char source []);

/*counts characters in array str until a NULL-character '\0' is found, then it returns that number excluding the '\0' one*/
int myStringLength(const char str []);

/*-returns 0 when the strings match, i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
-returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
-returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2*/
int myStringCompare(const char str1 [], const char str2 []);

int main()
{
  //Creates arrays to store names
  char namesOrig[row][col], namesSort[row][col], namesAlpha[row][col], namesNumber[row][col], temp[col];
  int x=0, r=0, c=0, b=0;

  //User designates i/o files
  char inputName[30];
  cout << "Input file name: ";
  cin >> inputName;
  ifstream inFile;
  inFile.open(inputName);

  char outputName[30];
  cout << "Output file name: ";
  cin >> outputName;
  ofstream outFile;
  outFile.open(outputName);

  //Adds numbers to array
  char asciiTable = 48;
  for (r=0; r<row; r++)
  {
    namesNumber[r][0] = asciiTable;
    namesNumber[r][1] = ' ';
    asciiTable++;
  }

  //Copies input file names into array
  for (r=0; r<row; r++)
  {
    inFile >> namesOrig[r];
    namesOrig[r][col] = '\0';
  }

  //Copies original array into numbers array
  for (r=0; r<row; r++)
  {
    for (c=2; c<col; c++)
    {
      namesNumber[r][c] = namesOrig[r][c-2];
    }
  }

  for (r=0; r<row; r++)
  {
    for (c=2; c<col; c++)
    myStringCopy(namesSort[r], namesNumber[r]);
  }

  for (r=0; r<row; r++)
  {
    myStringCopy(namesAlpha[r], namesNumber[r]);
  }

  //Prints unsorted names
  cout << "Unsorted Data (Original Input Order and Name)" << endl;
  cout << "===========================" << endl;
  for (x=0; x<row; x++)
  {
    cout << namesNumber[x] << endl;
  }
  cout << endl;

  //Sorts names by length
  for (r=0; r<row-1; r++)
  {
    for (c=r+1; (c<row); c++)
    {
      if (myStringLength(namesSort[r]) > myStringLength(namesSort[c]))
      {
        myStringCopy(temp, namesSort[c]);
        myStringCopy(namesSort[c], namesSort[r]);
        myStringCopy(namesSort[r], temp);
      }
    }
  }

  //Prints sorted names
  cout << "Sorted-by-Length Data (Original Input Order and Name)" << endl;
  cout << "===========================" << endl;
  for (x=0; x<row; x++)
  {
    cout << namesSort[x] << endl;
  }
  cout << endl;

  c=0;
  //Alphabetizes names
  for (r=0; r<row-1; r++)
  {
    for (c=r+1; c<row; c++)
    {
      if (myStringCompare(namesAlpha[r], namesAlpha[c]) > 0)
      {
        myStringCopy(temp, namesAlpha[r]);
        myStringCopy(namesAlpha[r], namesAlpha[c]);
        myStringCopy(namesAlpha[c], temp);
      }
    }
  }

  //Prints names alphabetically
  cout << "Alphabetically Sorted Data (Original Input Order and Name)" << endl;
  cout << "===========================" << endl;
  for (x=0; x<row; x++)
  {
    cout << namesAlpha[x] << endl;
  }

  //Prints terminal output to file
  //Saves original order
  outFile << "Unsorted Data (Original Input Order and Name)" << endl;
  outFile << "===========================" << endl;
  for (r=0; r<row; r++)
  {
    outFile << namesNumber[r] << endl;
  }
  outFile << endl;

  //Saves sorted-length order
  outFile << "Sorted-by-Length Data (Original Input Order and Name)" << endl;
  outFile << "===========================" << endl;
  for (r=0; r<row; r++)
  {
    outFile << namesSort[r] << endl;
  }
  outFile << endl;

  //Saves sorted-alpha order
  outFile << "Alphabetically Sorted Data (Original Input Order and Name)" << endl;
  outFile << "===========================" << endl;
  for (r=0; r<row; r++)
  {
    outFile << namesAlpha[r] << endl;
  }

  outFile.close();

  return 0;
}

//Functions//
void myStringCopy(char destination [], const char source [])
{
  for (int c=0; c<col; c++)
  {
    destination[c] = source[c];
  }
}
int myStringLength(const char str [])
{
  int size = 0;
  int x = 0;
  for (str[x]; str[x]!='\0'; x++)
    size++;
  return size;
}
int myStringCompare(const char str1 [], const char str2 [])
{
  int str1length = myStringLength(str1);
  int str2length = myStringLength(str2);

  char str3[str1length];
  char str4[str2length];
  int x=0;
  for (x=0; x<str1length; x++)
  {
    str3[x]=toupper(str1[x]);
  }
  for (x=0; x<str2length; x++)
  {
    str4[x] = toupper(str2[x]);
  }

  int i=0;
  int length=0;
  if (str1length>str2length)
    length=str1length;
  else if (str2length>str1length)
    length=str2length;
  else
    length=str1length;
  int breaker=0;
  for (i=2; i<length; i++)
  {
  //  printf("Iteration %d\n", i);
    if (str3[i]!=str4[i])
    {
      //printf("They are not equal.\n");
      if (str3[i]>str4[i])
      {
      //  printf("String 2 is less.\n");
        breaker = 1;
        return 1;
      }
      else if (str3[i]<str4[i])
      {
      //  printf("String 1 is less.\n");
        breaker = 1;
        return -1;
      }
    }
  }
  if (breaker==0)
    return 0;
}
