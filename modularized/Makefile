# Makefile
# PHY1610, Heather Fong, 2016.

# Define the compiler to use.
CXX = g++
GSLINC = /usr/local/lib/ # this has been set to work for my Mac OSX laptop - your directory may vary.

# Compiler and linker flags.
CXXFLAGS = -I${GSLINC} -O2 -pg
LDFLAGS = -L${GSLINC}
LDLIBS = -lgsl -lgslcblas
TICKTOCKDIR = ../../ticktock/

all: driver

# Links library files together to create the working executable
driver: driver.o initialize_ant.o time_step_ant.o output_time_step.o ticktock.o
	${CXX} -o driver driver.o initialize_ant.o time_step_ant.o output_time_step.o ticktock.o ${LDFLAGS} ${LDLIBS}

# Creates the library files
driver.o: driver.cpp initialize_ant.h time_step_ant.h output_time_step.h ${TICKTOCKDIR}ticktock.h
	${CXX} ${CXXFLAGS} -c -o driver.o driver.cpp
initialize_ant.o: initialize_ant.cpp
	${CXX} ${CXXFLAGS} -c -o initialize_ant.o initialize_ant.cpp
time_step_ant.o: time_step_ant.cpp
	${CXX} ${CXXFLAGS} -c -o time_step_ant.o time_step_ant.cpp
output_time_step.o: output_time_step.cpp
	${CXX} ${CXXFLAGS} -c -o output_time_step.o output_time_step.cpp
ticktock.o: ${TICKTOCKDIR}ticktock.cc
	${CXX} ${CXXFLAGS} -c -o ticktock.o ${TICKTOCKDIR}ticktock.cc

# Removes library files and executable file
clean:
	rm -f driver.o initialize_ant.o time_step_ant.o output_time_step.o ticktock.o driver
