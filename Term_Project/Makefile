.SUFFIXES: .cpp .o

OBJECTS = array_2d.o big_block.o block.o color_block.o cross_block.o fold_block.o tree_block.o 

MAIN = main.o $(OBJECTS)

CXX = g++

TARGET = puyopuyo

$(TARGET) : $(MAIN)

	      $(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(TARGET) $(MAIN)

array_2d.o = array_2d.cpp
big_block.o = big_block.cpp
block.o = block.cpp
colo_block.o = color_block.cpp
cross_block.o = cross_block.cpp
tree_block.o = tree_block.cpp
fold_block.o = fold_block.cpp

