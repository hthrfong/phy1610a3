// PHY1610 Assignment 2
// Heather Fong, January 28, 2016
// Driver
// This code runs a simulation of ants walking on a table. The direction in which they walk, depends on where they are on the table, and they can fall of the edge. The program prints the number of ants left on the table after every time step. This uses three header files that run the simulation. The program can be compiled with 'Makefile'.

#include <iostream>
#include <cmath>
#include <rarray>
#include "../ticktock/ticktock.h"
#include "initialize_ant.h"
#include "time_step_ant.h"
#include "output_time_step.h"
#include <boost/test/unit_test.hpp>
#define BOOST_TEST_MODULE myTest

//MAIN//
int main()
{
  // defining variables
  int arrsize = 356; // size of array
  int total_ants = 1010; // initial number of ants
  float z_cycles = 0.3; // varies velocity of ants
  float d_amplitude = 1.9; // varies location of ants
  float still_ant_fraction = 0.8; // varies fraction of ants that don't move
  rarray<float,2> velocity_of_ants(arrsize,arrsize); // ant velocity
  rarray<float,2> number_of_ants(arrsize,arrsize); // number of ants
  rarray<float,2> new_number_of_ants(arrsize,arrsize); // updated number of ants
  int t = 2; // amount of time we observe
  
  // initialize
  initialize_ant(arrsize,total_ants,z_cycles, velocity_of_ants, number_of_ants);
  
  // run simulation
  //float old_totants = output_time_step(arrsize,t,number_of_ants,new_number_of_ants); // output number of ants on table
  time_step_ant(arrsize, d_amplitude, total_ants, still_ant_fraction,	\
		velocity_of_ants, number_of_ants, new_number_of_ants); // run through simulation to see how many ants remain
  float totants = output_time_step(arrsize,t,number_of_ants,new_number_of_ants); // spit out new number of ants
  std::cout << total_ants-totants << std::endl;
  return total_ants-totants;
}

BOOST_AUTO_TEST_CASE(my_test)
{
  BOOST_CHECK(main()>0); // if main()>0, then that means number of ants have decreased - good.
  BOOST_REQUIRE(main()>0); // set this as a requirement
  if (main()<0) BOOST_ERROR("Why are there more ants than before? Error."); // if main()<0, then number of ants have increased, which is not good.
  BOOST_CHECK_MESSAGE(main()>0, "Less ants than before. Good.");
}
BOOST_AUTO_TEST_SUITE_END()
