CXX        = g++
CXXFLAGS   = -c -g -Wall -std=c++14
SOURCES    = $(wildcard *.cpp)
OBJECTS    = $(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX)  $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF  ./.depend;

include .depend

clean:
	@rm -f *~
	@rm -f *.o

.PHONY: clean
