// A signature Nick Alvarez program, produced for Project 8, due November 27, 2018
/* This program will take in two strings, determine alphabetical order, concatenate them, and copy them.*/

//Apologies for the mess.

#include <stdio.h>
#include <ctype.h>

int strlength(char* c); //Calculates the length of the strings
char* strcopy(char *c2, char *c1); //Copies string 1 into string 2
char* strconcat(char *c2, char *c1); //Copies string 1 into the end of string 2
int strcomp(char *c1, char *c2); //Determines alphabetical order of strings

int main()
{
  char str1[21];
  char str2[41];
  char *c1, *c2;
  c1 = str1;
  c2 = str2;
  //Get user input
  printf("Please enter the first string: ");
  scanf("%20s", str1);
  printf("Please enter the second string: ");
  scanf("%20s", str2);

  //Length of strings
//  int size1=0;
//  int i=0;
/*  for (c1=&str1[0]; *c1!=NULL; c1++)
  {
    printf("%c\n", *c1);
    size1++;
    printf("%d\n", size1);
  }*/
  printf("The length of string 1 is: %d\n", strlength(str1));
  printf("The length of string 2 is: %d\n", strlength(str2));

  //Checks alphabetical order
  if (strcomp(str1, str2)==1)
    printf("String 1 comes before string 2 alphabetically.\n");
  else if (strcomp(str1, str2)==-1)
    printf("String 2 comes before string 1 alphabetically.\n");
  else
    printf("The two strings are the same.\n");

  //Concatenates strings
  printf("String 1 after concatenation: %s\n", str1);
  /*int z=0;
  int d=5;
  while (str1[z]!='\0')
  {
    printf("%s, %s\n", str1,str2);
    str2[d]=str1[z];
    printf("%s, %s\t\t%d\n", str1,str2, z++);
  //  c1++;
    d++;
  }*/

  printf("String 2 after concatenation: %s\n", strconcat(str2, str1));

  //Copies strings
  printf("String 1 after copying: %s\n", str1);
  printf("String 2 after copying: %s\n", strcopy(str2, str1));

  return 0;
}

//WORKS
int strlength(char *c)
{
  //*c=str1 or str2
  int size = 0;
  for (c; *c!='\0'; c++)
    size++;
  return size;
}

//WORKS
char* strcopy(char *c2, char *c1)
{
  c2=c1;
/*  int i=0;
  for (c2=&c2[0]; i<=21; c2++)
  {
    *c2+=*c1;
    c1++;
    i++;
  }
  c2=&c2[0];*/
  return c2;
}

char* strconcat(char *c2, char *c1)
{
  /*c1=&c1[strlength(c1)];
  int i=1;
  int c2size = strlength(c2);
  for (c2=&c2[0]; *c2!='\0'; c2++)
  {
    printf("%s, %s\n", c1,c2);
    *(c1++)=*c2;
    printf("%s\t%s\t\t%d\n", c1,c2, i++);
    //c1++;
  }*/
//  int len = strlength(c1) + strlength(c2);
  char *c3, *c4;
  c3=c1;
  c4=c2;
  c3=&c3[0];
  c4=&c4[strlength(c2)];
  int i=1;
  while (*c3!='\0')
  {
  //  printf("%s, %s\n", c1,c2);
    *c4=*c3;
  //  printf("%s, %s\t\t%d\n", c1,c2, i++);
    c3++;
    c4++;
  }
//  c2=&c2[len];
//  *c2='\0';
//  *(c2++)=*c1;
//  c2=&c2[c2size+1];
//  c2=c1;
//  c2=&c2[0];
  return c2;
}

//WORKS
int strcomp(char *c1, char *c2)
{
  int str1length = strlength(c1);
  int str2length = strlength(c2);

  char str3[str1length];
  char str4[str2length];
  int x=0;
  for (x=0; x<str1length; x++)
  {
    str3[x]=toupper(*c1);
    c1++;
  }
  for (x=0; x<str2length; x++)
  {
    str4[x] = toupper(*c2);
    c2++;
  }

  //printf("%s, %s\n", str3, str4);
  /*toupper(*c2);
  toupper(*c1);*/
  //  if (*c1==*c2)
  //    return 0;
  c2=&c2[0];
  int i=0;
  int length=0;
  if (str1length>str2length)
    length=str1length;
  else if (str2length>str1length)
    length=str2length;
  else
    length=str1length;
  _Bool breaker=0;
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
