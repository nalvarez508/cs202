#include <iostream>
#include <fstream>
#include "Sensor.h"
#include "MainFunctions.h"
using namespace std;

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

//Default
Sensor::Sensor() :
  m_extracost(DEFAULT_FLOAT)
{
  setType(DEFAULT_TYPE);
}
//Parameterized
Sensor::Sensor(const char * type, float extracost) :
//Here, we want to assign values to extracost based on what is in m_type
  m_extracost(extracost)
{
  setType(type);
}
//Copy
Sensor::Sensor(const Sensor & other) :
  m_extracost(other.m_extracost)
{
  setType(other.m_type);
}

//Methods
bool operator==(const Sensor& s1, const Sensor& s2)
{
  return ((myStringCompare(s1.getType(), s2.getType())));
}

//Get, set
char * getType() const
{
  return m_type;
}
void setType(const char * type)
{
  char * tPtr;
  tPtr = type;
  myStringCopy(m_type);
  tPtr++;
  while (*tPtr!='}')
  {
    if (*tPtr=='g')
    {
        gps_cnt++;
        tPtr+=4;
        if (*tPtr==' ')
        {
          tPtr--;
        }
      }
    if (*tPtr=='c')
    {
        camera_cnt++;
        tPtr+=7;
        if (*tPtr==' ')
        {
          tPtr--;
        }
      }
    if (*tPtr=='l')
    {
        lidar_cnt++;
        tPtr+=6;
        if (*tPtr==' ')
        {
          tPtr--;
        }
      }
    if (*tPtr=='r')
    {
        radar_cnt++;
        tPtr+=6;
        if (*tPtr==' ')
        {
          tPtr--;
        }
      }
  }
}
float getExtraCost() const
{
  return m_extracost;
}
void setExtraCost(float extracost)
{
  m_extracost = extracost;
}
int static getGPS()
{
  return gps_cnt;
}
void resetGPS()
{
  gps_cnt = 0;
}
int static getCamera()
{
  return camera_cnt;
}
void resetCamera()
{
  camera_cnt = 0;
}
int static getLidar()
{
  return lidar_cnt;
}
void resetLidar()
{
  lidar_cnt = 0;
}
int static getRadar()
{
  return radar_cnt;
}
void resetRadar()
{
  radar_cnt = 0;
}
