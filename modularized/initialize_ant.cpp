// initialize_ant.cpp
// PHY1610, Heather Fong, 2016.
// This module initializes the ant simulation. Sets up velocity_of_ants and number_of_ants arrays that will be used in the other modules to determine whether or not the ants remain on the table.
#include <cmath>
#include <rarray>
#include <iostream>
#include "initialize_ant.h"

void initialize_ant(int arrsize, int total_ants, float z_cycles,\
		    rarray<float,2> &velocity_of_ants, \
		    rarray<float,2> &number_of_ants) {
  for (int i=0;i<arrsize;i++) {
    for (int j=0;j<arrsize;j++) {
      velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/(arrsize*10))+1); // determines ant velocity
    }
  }
  int n = 0;
  float z = 0;
  number_of_ants.fill(0.0); // sets all elements in number_of_ants to be 0
  while (n<total_ants) { // loops through each ant
    for (int i=0;i<arrsize;i++) {
      for (int j=0;j<arrsize;j++) {
	z += sin(z_cycles*(i+j));
	if (z>1 and n!=total_ants) { 
	  number_of_ants[i][j] += 1; // sets certain elements in number_of_ants to be 1
	  n += 1;
	}
      }
    }
  }
  //std::cout << number_of_ants[0][0] << "Test test test \n";
}
