#ifndef SENSOR_H
#define SENSOR_H

//Constants
const int DEFAULT_INT = 0;
const float DEFAULT_FLOAT = 0.0;
const char t_none[5] = "none";
const char t_gps[4] = "gps";
const char t_camera[7] = "camera";
const char t_lidar[6] = "lidar";
const char t_radar[6] = "radar";

class Sensor
{
  friend bool operator==(const Sensor& s1, const Sensor& s2);
public:
  //Default
  Sensor();
  //Parameterized
  Sensor(const char * type, float extracost=DEFAULT_FLOAT);
  //Copy
  Sensor(const Sensor & other);

  //Get, set
  char * getType() const;
  void setType(const char * type);
  float getExtraCost() const;
  void setExtraCost(float extracost);
  int static getGPS();
  void resetGPS();
  int static getCamera();
  void resetCamera();
  int static getLidar();
  void resetLidar();
  int static getRadar();
  void resetRadar();

private:
  static int gps_cnt;
  static int camera_cnt;
  static int lidar_cnt;
  static int radar_cnt;
  char m_type[256];
  float m_extracost;
};
#endif
