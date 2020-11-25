TARGET = proj7
CXX = g++ #compiler command to be used
CXX_FLAGS = -Wall#compilation flags to be used (here std=c++11 is just for reference, not necessary)

all: $(TARGET)

$(TARGET): $(TARGET).o MyString.o
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(TARGET).o MyString.o

$(TARGET).o: $(TARGET).cpp MyString.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

MyString.o: MyString.h

clean:
	-rm -f *.o
	-rm -f $(TARGET)
