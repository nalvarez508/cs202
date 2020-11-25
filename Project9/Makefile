TARGET = proj9
CXX = g++
CXX_FLAGS = -Wall

all: $(TARGET)

$(TARGET): $(TARGET).o ArrayQueue.o NodeQueue.o DataType.o
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(TARGET).o ArrayQueue.o NodeQueue.o DataType.o

$(TARGET).o: $(TARGET).cpp ArrayQueue.h NodeQueue.h DataType.h
	$(CXX) $(CXX_FLAGS) -c $(TARGET).cpp

ArrayQueue.o: ArrayQueue.h DataType.h
NodeQueue.o: NodeQueue.h DataType.h
DataType.o: DataType.h

clean:
	-rm -f *.o
	-rm -f $(TARGET)
