// output_time_step.cpp
// PHY1610, Heather Fong, 2016.
// This module prints out the number of ants remaining on the table time_step_ant. The time t and number of ants is printed. The number of ants is printed in integer because it's weird for a fraction of the ant to be on/off the table.

#include <cmath>
#include <rarray>
#include <iostream>
#include "output_time_step.h"

float output_time_step(int arrsize, int t, rarray<float,2> &number_of_ants, \
		      rarray<float,2> &new_number_of_ants) {
  float totants = 0.0;
  for (int i=0;i<arrsize;i++) {
    for (int j=0;j<arrsize;j++) {
      totants += number_of_ants[i][j];
    }
  }
  int remaining_ants = totants; // turns number of ants remaining into an integer (because it doesn't make sense for a fraction of an ant to be on the table...)
  if (t==0) {
    std::cout << "Time step" << "\t" << "Ants left" << "\t" << "Elapsed time" << std::endl; // print out headers at the beginning
  }
  std::cout << t << "\t" << remaining_ants << "\t"; // print out time and number of ants remaining at that time step
  new_number_of_ants.fill(0.0); // reset new_number_of_ants to 0-array
  return totants;
}
