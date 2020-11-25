TARGET = proj4
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall #compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o Agency.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o Agency.o -o $(TARGET)
$(TARGET).o: $(TARGET).cpp Agency.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp
Agency.o: Agency.cpp Agency.h
	$(CXX) $(CXX_FLAGS) -c Agency.cpp

$(TARGET): $(TARGET).o Car.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o Car.o -o $(TARGET)
$(TARGET).o: $(TARGET).cpp Car.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp
Car.o: Car.cpp Car.h
	$(CXX) $(CXX_FLAGS) -c Car.cpp

$(TARGET): $(TARGET).o Sensor.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o Sensor.o -o $(TARGET)
$(TARGET).o: $(TARGET).cpp Sensor.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp
Sensor.o: Sensor.cpp Sensor.h
	$(CXX) $(CXX_FLAGS) -c Sensor.cpp

$(TARGET): $(TARGET).o MainFunctions.o
	$(CXX) $(CXX_FLAGS) $(TARGET).o MainFunctions.o -o $(TARGET)
$(TARGET).o: $(TARGET).cpp MainFunctions.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp
MainFunctions.o: MainFunctions.cpp MainFunctions.h
	$(CXX) $(CXX_FLAGS) -c MainFunctions.cpp

clean:
	-rm -f *.o
	-rm -f $(TARGET)
