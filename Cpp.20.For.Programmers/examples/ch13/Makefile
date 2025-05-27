FMTLIB_DIR = $(HOME)/local/fmtlib

CXX = g++
CXXFLAGS = -Wall -std=c++20 -I$(FMTLIB_DIR)/include
LDFLAGS = -Wl,-rpath,$(FMTLIB_DIR)/lib -Wl,--enable-new-dtags -L$(FMTLIB_DIR)/lib
LDLIBS = -lfmt

SOURCES = $(shell ls *.cpp)
PROGRAMS = $(patsubst %.cpp,%,$(SOURCES))

.PHONY: all 
all: $(PROGRAMS)

$(PROGRAMS): %: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(PROGRAMS)

