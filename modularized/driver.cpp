// PHY1610 Assignment 2
// Heather Fong, January 28, 2016
// Driver
// This code runs a simulation of ants walking on a table. The direction in which they walk, depends on where they are on the table, and they can fall of the edge. The program prints the number of ants left on the table after every time step. This uses three header files that run the simulation. The program can be compiled with 'Makefile'.

#include <iostream>
#include <cmath>
#include <rarray>
#include "../../ticktock/ticktock.h"
#include "initialize_ant.h"
#include "time_step_ant.h"
#include "output_time_step.h"
using namespace std;

//MAIN//
int main()
{
  // define stopwatch
  TickTock stopwatch;
  stopwatch.tick(); // start stopwatch  
  // defining variables
  int arrsize = 356; // size of array
  int total_ants = 1010; // initial number of ants
  float z_cycles = 0.3; // varies velocity of ants
  float d_amplitude = 1.9; // varies location of ants
  float still_ant_fraction = 0.8; // varies fraction of ants that don't move
  rarray<float,2> velocity_of_ants(arrsize,arrsize); // ant velocity
  rarray<float,2> number_of_ants(arrsize,arrsize); // number of ants
  rarray<float,2> new_number_of_ants(arrsize,arrsize); // updated number of ants
  int time = 40; // amount of time we observe
  
  // initialize
  initialize_ant(arrsize,total_ants,z_cycles, velocity_of_ants, number_of_ants);
  cout << "Initialization complete. Ants are on table." << endl;

  double timestring1 = stopwatch.silent_tock();
  
  cout << "Watching ants walk on the table... " << timestring1 << " sec"  << endl ;
  
  // run simulation
  for (int t=0;t<time;t++) {
    float totants = output_time_step(arrsize,t,number_of_ants,new_number_of_ants); // output number of ants on table
    stopwatch.tock("Time measurement:");
    time_step_ant(arrsize, d_amplitude, totants, still_ant_fraction,	\
      		  velocity_of_ants, number_of_ants, new_number_of_ants); // run through simulation to see how many ants remain

    double timestring2 = stopwatch.silent_tock();
    cout << timestring2 << " sec elapsed" << endl;
  }

  double timestring3 = stopwatch.silent_tock();
  cout << "Done! Exiting... " << timestring3 << " sec elapsed" << endl;  
  return 0;
}
