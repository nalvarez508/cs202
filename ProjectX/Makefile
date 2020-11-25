TARGET = projX
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall#compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o DataType.o SmartPtr.o
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(TARGET).o DataType.o SmartPtr.o

$(TARGET).o: $(TARGET).cpp DataType.h SmartPtr.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

DataType.o: DataType.h
SmartPtr.o: SmartPtr.h DataType.h

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	
