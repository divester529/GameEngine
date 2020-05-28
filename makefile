CC = g++

CFLAGS = -g
LFLAGS = -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglu32 -lglew32

TARGET = game

all: $(TARGET)

run: all
	./game.exe

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) *.cpp */*.cpp $(LFLAGS)
