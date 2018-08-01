EXECUTABLE = main
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES: .cpp=.o)

CXX=g++
CXXFLAGS=-g -Wall -std=c++11
.PHONY: all test clean
-include $(DEPS)

all: $(EXECUTABLE)

$(EXECUTABLE):  $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.c %.h
	        $(CC) $(CCFLAGS) -c $<

%.o: %.c
	        $(CC) $(CCFLAGS) -c $<

test: main
	./$(EXECUTABLE)

lint:
	astyle --style=allman --unpad-paren --pad-oper --convert-tabs --pad-header --delete-empty-lines $(SOURCES) $(HEADERS)

clean:
	rm -f *.class *.o *.orig $(EXECUTABLE)
