CXX = clang++
CXXFLAGS = -g -O3 -mavx2 -Wall -pedantic
INCLUDES = 
LDFLAGS = -L$(HOME)/local/gperftools/lib/
LDLIBS = -lprofiler

PROGS =	example

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

clean:
	@$(RM) $(PROGS) *.o prof.data prof.pdf
	@echo "clean OK!"

example: compare.C compare1.C compare2.C example.C
	$(CXX) -o $@ $^ $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

