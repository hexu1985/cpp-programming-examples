CXX = clang++
CXXFLAGS = -g -O3 -mavx2 -Wall -pedantic
INCLUDES = 
LDFLAGS = 
LDLIBS = 

PROGS =	benchmark

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o
	@echo "clean OK!"

benchmark: 05a_compare_timer.C
	$(CXX) -o $@ $^ $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

