.SUFFIXES: .cpp .o

OBJECTS = bike.o car.o vehicle.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
	
	$(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(TARGET) $(OBJECTS)

bike.o = bike.cpp
car.o = car.cpp
vehicle.o = vehicle.cpp
main.o = main.cpp