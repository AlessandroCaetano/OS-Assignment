CC=g++
CFLAGS=-g -O2 -c -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11
LDFLAGS=  -w -Wall -ansi -pedantic -I. -pthread -lm -std=c++11
SOURCES=main.cpp Buffer.cpp ErrorChecker.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=buffer

all: $(SOURCES) $(EXECUTABLE) clean

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o all