# Makefile
# PHY1610, Heather Fong, 2016.

# Define the compiler to use.
CXX = g++
GSLINC = /usr/local/lib/ # this has been set to work for my Mac OSX laptop - your directory may vary.

# Compiler and linker flags.
CXXFLAGS = -I${GSLINC} -O2
LDFLAGS = -L${GSLINC}
LDLIBS = -lgsl -lgslcblas
TICKTOCKDIR = ../../ticktock/

all: ants

ants: ants.o ticktock.o
	${CXX} -o ants ants.o ticktock.o ${LDFLAGS} ${LDLIBS}

# Creates the library files
ants.o: ants.cc ${TICKTOCKDIR}ticktock.h
	${CXX} ${CXXFLAGS} -c -o ants.o ants.cc
ticktock.o: ${TICKTOCKDIR}ticktock.cc
	${CXX} ${CXXFLAGS} -c -o ticktock.o ${TICKTOCKDIR}ticktock.cc

# Removes library files and executable file
clean:
	rm -f ants.o ticktock.o ants
