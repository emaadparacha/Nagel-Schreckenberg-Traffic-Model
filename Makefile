#
# Makefile for trafficSim
#
# Type 'make help' for usage
#

# Variables controlling the settings for the compilation.
CXX = g++
CPPFLAGS =
CXXFLAGS = -std=c++14
LDFLAGS =
LDLIBS =

## all: build application and documentation
all: readINIFile.cpp trafficMaker.cpp trafficMovement.cpp outFile.cpp trafficSim.cpp trafficSimp doc

## readINIFile: build readINIFile
readINIFile: readINIFile.cpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -c -o $@.o

## trafficMaker: build trafficMaker
trafficMaker: trafficMaker.cpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -c -o $@.o

## trafficMovement: build trafficMovement
trafficMovement: trafficMovement.cpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -c -o $@.o

## outFile: build outFile
outFile: outFile.cpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -c -o $@.o

## trafficSim: build trafficSim
trafficSim: trafficSim.cpp
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -c -o $@.o

## trafficSimp: build trafficSim program
trafficSimp: readINIFile.o trafficMaker.o trafficMovement.o outFile.o trafficSim.o
	${CXX} ${CPPFLAGS} ${CXXFLAGS} $^ -o trafficSim

## run: run the 'antsontable' application and create ants.txt
run: readINIFile.cpp trafficMaker.cpp trafficMovement.cpp outFile.cpp trafficSimp
	./trafficSim

## clean: remove intermediate generated files
clean:
	$(RM) trafficSim Doxyfile trafficSnapshot.png trafficSim.pdf trafficData.txt
	$(RM) *.o
	$(RM) -r latex
	$(RM) -r html

## help: print all commented 'make' targets
# (the sed command displays all lines from the Makefile that start with '##')
help:
	@sed -n 's/^## *\(.*\): */\1:\t/p' Makefile Documentation.mk Plotting.mk

# all targets can be files except the following:
.PHONY: all clean run help

# documentation and plotting dealt with in separate Makefiles
include Documentation.mk
include Plotting.mk
