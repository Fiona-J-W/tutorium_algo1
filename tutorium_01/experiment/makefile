# Makefile for searcher
# created with makefile-creator


####################
#Settings:


CXX ?= g++
FLAGS +=  -Wall -Wextra -pedantic -std=c++11 -O3 -mtune=native -Werror -DMAX_ELEMENT_COUNT=1000 -DSTEP=1 
LIBS += 
INCLUDES += 
TARGET = searcher
OBJECTS = build/main.o


####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

build/%.o:
	@if test ! -d 'build'; then mkdir 'build'; echo "created 'build'" ; fi
	$(CXX) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm build/*.o

all: $(TARGET)


####################
#Dependencies:


build/main.o: src/main.cpp makefile

