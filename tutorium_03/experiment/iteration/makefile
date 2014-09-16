# Makefile for iterator
# created with makefile-creator


####################
#Settings:


CXX ?= g++
FLAGS +=  -Wall -Wextra -pedantic -std=c++1y -O3 -mtune=native -Werror 
LIBS += 
INCLUDES += 
TARGET = iterator
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

