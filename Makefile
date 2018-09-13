# Voro++ makefile
#
# Author : Chris H. Rycroft (LBL / UC Berkeley)
# Email  : chr@alum.mit.edu
# Date   : August 30th 2011

# Load the common configuration file
include ./config.mk

# List of executables

EXECUTABLE=random_cauchy_3D

all:$(EXECUTABLE)

# Makefile rules

random_cauchy_3D: voronoi_random.cc
	$(CXX) $(CFLAGS) $(E_INC) $(E_LIB) -o $(EXECUTABLE) voronoi_random.cc -lvoro++
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
