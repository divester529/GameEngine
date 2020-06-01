src = $(wildcard src/*.cpp) \
			$(wildcard src/renderer/*.cpp) \
			$(wildcard src/system/*.cpp) \
			$(wildcard src/input/*.cpp) \
			$(wildcard src/util/*.cpp)
obj = $(src:.cpp=.o)
CC = g++

CFLAGS = -g
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglu32 -lglew32

TARGET = game

all: $(TARGET)

run: all
	./game.exe

clean:
	rm -f $(obj) myprog

$(TARGET): $(obj)
	$(CC) $(CFLAGS) -o $(TARGET) $^ $(LDFLAGS)
