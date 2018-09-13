# Voro++, a 3D cell-based Voronoi library
#
# Author : Chris H. Rycroft (LBL / UC Berkeley)
# Email  : chr@alum.mit.edu
# Date   : August 28th 2011

# This a common configuration file that includes definitions used by all
# the Makefiles.

# C++ compiler
CXX=icpc

# Flags for the C++ compiler
CFLAGS=-Wall -ansi -pedantic -O3 -std=c++11

# Relative include and library paths for compilation of the examples
E_INC=-I/home/emi/Voro++/voro++-0.4.6/src
E_LIB=-L/home/emi/Voro++/voro++-0.4.6/src

# Installation directory
PREFIX=/usr/local

# Install command
INSTALL=install

# Flags for install command for executable
IFLAGS_EXEC=-m 0755

# Flags for install command for non-executable files
IFLAGS=-m 0644
