.SUFFIXES: .cpp .o

OBJECTS = Complex.o Float.o Integer.o test.o

CXX = g++

CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
		$(CXX) -o $(TARGET) $(OBJECTS)

clean : 
		rm -rf $(TARGET) $(OBJECTS)

test.o = test.cpp
Complex.o = Complex.cpp
Float.o = Float.cpp
Integer.o = Integer.cpp

