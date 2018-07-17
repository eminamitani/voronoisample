# Voro++ makefile
#
# Author : Chris H. Rycroft (LBL / UC Berkeley)
# Email  : chr@alum.mit.edu
# Date   : August 30th 2011

# Load the common configuration file
include ./config.mk

# List of executables
EXECUTABLES=test  random_test cauchy test_cauchy

# Makefile rules

test: random_points_periodic.cc
	$(CXX) $(CFLAGS) $(E_INC) $(E_LIB) -o test random_points_periodic.cc -lvoro++

random_test: random.cc 
	g++ -std=c++11 -o random_test random.cc

cauchy: random_cauchy.cc
	g++ -std=c++11 -o cauchy random_cauchy.cc

test_cauchy: voronoi_random.cc
	$(CXX) $(CFLAGS) $(E_INC) $(E_LIB) -o test_cauchy voronoi_random.cc -lvoro++
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
