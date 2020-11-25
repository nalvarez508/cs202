TARGET = proj6
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall#compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o Vehicle.o Car.o
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(TARGET).o Vehicle.o Car.o

$(TARGET).o: $(TARGET).cpp Vehicle.h Car.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

Vehicle.o: Vehicle.h
Car.o: Car.h Vehicle.h

clean:
	-rm -f *.o
	-rm -f $(TARGET)
