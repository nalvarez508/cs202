#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H
#include <iostream>
#include <fstream>

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
void printMenu(); //Done

/*Asks user for input file*/
void getFile(Agency agn); //Done

/*Prints array to terminal*/
void printCarData2Term(Agency agn); //Done?

/*Prints out total number of sensors*/
void printTotalSensors(Sensor s); //Done

/*Sorts cars by ascending price*/
//void sortCars(RentalCar * arr);

//Finds the most expensive car and asks the user if they want to rent it
void car2Rent(Car c); //Done

#endif
