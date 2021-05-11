SOURCES = $(wildcard *.cpp) $(wildcard imgui/*.cpp) $(wildcard integration/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))
DEPS = $(patsubst %.cpp,%.d,$(SOURCES))

BIN = test

CPP = g++
LDFLAGS = `sdl2-config --libs` -lbgfx

CFLAGS = 	-MMD \
			`sdl2-config --cflags` -Wall \
		 	-O0 -g

INCLUDE = -I./ -I./integration

all: $(BIN)

$(BIN): $(OBJS) 
	$(CPP) $(LDFLAGS) -o$(BIN) $(OBJS)
	echo "Done!"

%.o: %.cpp
	$(CPP) -c $(INCLUDE) $(CFLAGS) $< -o $@   

.PHONY: clean run

clean:
	rm -rf $(OBJS)
	rm -rf $(DEPS)

dist-clean:
	rm -rf $(BIN)

run:
	./$(BIN)

-include $(DEPS)