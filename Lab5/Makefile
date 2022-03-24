CC = g++
CFLAGS = -c -MMD
LFLAGS = -Wall -Wextra -g 
LDFLAGS ?= -lX11
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = ex

all: $(EXECUTABLE) clean
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o:%.cpp
	$(CC) $(CFLAGS) $<
	
-include *.d

clean:
	rm -f *.d
	rm -f *.o