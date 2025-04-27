
GBENCH_DIR=$(HOME)/local/google_benchmark

RM = rm -f
CXX = clang++
CXXFLAGS = -g -O3 -mavx2 -Wall -pedantic
INCLUDES = -I$(GBENCH_DIR)/include
LDLIBS = -pthread -lbenchmark
LDFLAGS = -Wl,-rpath,$(GBENCH_DIR)/lib -Wl,--enable-new-dtags -L$(GBENCH_DIR)/lib
VPATH = 

SOURCES = $(shell ls *.cpp)
PROGS = benchmark

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

benchmark: 11_compare_mbm.C 11_compare_mbm_a.C 11_compare_mbm_b.C 11_compare_mbm_c.C
	$(CXX) -o $@ $^ $(CXXFLAGS) $(INCLUDES) $(LDFLAGS) $(LDLIBS)

