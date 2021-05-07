SOURCES = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))
DEPS = $(patsubst %.cpp,%.d,$(SOURCES))

BIN = test

CPP = g++
LDFLAGS = `sdl2-config --libs` -lbgfx

CFLAGS = 	-MMD \
			`sdl2-config --cflags` -Wall \
		 	-O0 -g

INCLUDE = ./imgui/

all: $(BIN)

$(BIN): $(OBJS) 
	$(CPP) $(LDFLAGS) -o$(BIN) $(OBJS)

%.o: %.cpp
	$(CPP) -c -I$(INCLUDE) $(CFLAGS) $< -o $@    

.PHONY: clean run

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)
	rm -rf $(BIN)

run:
	./$(BIN)

-include $(DEPS)