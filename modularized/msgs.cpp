// time_step_ant.cpp
// PHY1610, Heather Fong, 2016.
// This module determines whether or not the ants fall off the table at a particular time step. number_of_ants is the array with the initial number of ants, and new_number_array is the array with the remaining number of ants after they have walked.

#include <cmath>
#include <rarray>
#include "time_step_ant.h"
#define BOOST_TEST_MODULE myTest
#include <boost/test/unit_test.hpp>

float time_step_ant(int arrsize, float d_amplitude, float totants, float still_ant_fraction,\
		   rarray<float,2> &velocity_of_ants, rarray<float,2> &number_of_ants, \
		   rarray<float,2> &new_number_of_ants) {

  float old_totants = 0;
  for (int i=0;i<arrsize;i++) {
    for (int j=0;j<arrsize;j++) {
      int di = d_amplitude*sin(velocity_of_ants[i][j]); // determines ant's location
      int dj = d_amplitude*cos(velocity_of_ants[i][j]); // determine's ant's location
      int i2 = i + di;
      int j2 = j + dj;
      // some ants do not walk
      new_number_of_ants[i][j] += still_ant_fraction*number_of_ants[i][j];
      old_totants += number_of_ants[i][j];
      // the rest of the ants walk, but some fall off the table
      if (i2>=0 and i2<arrsize and j2>=0 and j2<arrsize) {
	new_number_of_ants[i2][j2] += (1.0-still_ant_fraction)*number_of_ants[i][j]; // ants that do not fall off the table
      }
    }
  }
  number_of_ants = new_number_of_ants.copy(); // make number_of_ants = new_number_of_ants
  for (int i=0;i<arrsize;i++) {
    for (int j=0;j<arrsize;j++) {
      //number_of_ants[i][j] = new_number_of_ants[i][j];
      totants += number_of_ants[i][j]; // count up array elements to find total of ants still on table
    }
  }
  return old_totants-totants;
}

BOOST_AUTO_TEST_CASE(my_test)
{
  int arrsize = 356;
  int total_ants = 1010;
  float z_cycles = 0.3;
  float d_amplitude = 1.9;
  float still_ant_fraction = 0.8;
  rarray<float,2> velocity_of_ants(arrsize,arrsize);
  rarray<float,2> number_of_ants(arrsize,arrsize);
  rarray<float,2> new_number_of_ants(arrsize,arrsize);
  float totants = 950;
  new_number_of_ants.fill(0.0);

  for (int i=0;i<arrsize;i++) {
    for (int j=0;j=arrsize;j++) {
      velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/(arrsize*10))+1);
    }
  }
  int n = 0;
  float z = 0;
  number_of_ants.fill(0.0);
  while (n<total_ants) {
    for (int i=0;i<arrsize;i++) {
      for (int j=0;j<arrsize;j++) {
	z += sin(z_cycles*(i+j));
	if (z>1 and n!=total_ants) {
	  number_of_ants[i][j] += 1;
	  n += 1;
	}
      }
    }
  }

  BOOST_CHECK(time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction, velocity_of_ants, number_of_ants, new_number_of_ants)>0);
  BOOST_REQUIRE(time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction, velocity_of_ants, number_of_ants, new_number_of_ants)>0);
  if time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction, velocity_of_ants, number_of_ants, new_number_of_ants)<0 BOOST_ERROR("Uh oh! There are more ants than before!");
  if time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction, velocity_of_ants, number_of_ants, new_number_of_ants)<0 BOOST_FAIL("Uh oh! There are more ants than before!");
  BOOST_CHECK_MESSAGE(time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction, velocity_of_ants, number_of_ants, new_number_of_ants)>0, "More ants have fallen off.");
}
BOOST_AUTO_TEST_SUITE_END ()
