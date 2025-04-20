CXX = clang++
CXXFLAGS = -g -O3 -mavx2 -Wall -pedantic
PROGRAM = example

SOURCES = 02_substring_sort.C
OBJECTS = $(patsubst %.C,%.o,$(SOURCES))

.PHONY: all 
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS)

$(OBJECTS): %.o: %.C
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(PROGRAM) out.* perf.data* flamegraph.svg

