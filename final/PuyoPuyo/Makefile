.SUFFIXES: .cpp .o

CONTROLLER = controller
CONTROLLER_OBJECTS = $(CONTROLLER)/controller.o

PUYO = puyo
PUYO_OBJECTS = $(PUYO)/board.o

SHAPE = $(PUYO)/shape_block
SHAPE_OBJECTS = $(SHAPE)/cross_block.o $(SHAPE)/fold_block.o $(SHAPE)/tree_block.o

BLOCK = $(SHAPE)/block
BLOCK_OBJECTS = $(BLOCK)/block.o $(BLOCK)/block_group.o

OBJECTS = $(CONTROLLER_OBJECTS) $(PUYO_OBJECTS) $(SHAPE_OBJECTS) $(BLOCK_OBJECTS)

MAIN = main.o $(OBJECTS)

CXX = g++
TARGET = Puyo_Puyo

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean :
	rm -rf $(MAIN) $(TARGET)