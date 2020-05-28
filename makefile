src = $(wildcard src/*.cpp) \
			$(wildcard src/renderer/*.cpp) \
			$(wildcard src/system/*.cpp) \
			$(wildcard src/input/*.cpp)
obj = $(src:.cpp=.o)
CC = g++

CFLAGS = -g
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglu32 -lglew32

TARGET = game

all: $(TARGET)

run: all
	./game.exe

$(TARGET): $(obj)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDFLAGS)
