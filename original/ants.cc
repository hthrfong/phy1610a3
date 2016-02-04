#include <cmath>
#include <iostream>
#include "../ticktock/ticktock.h"

int main()
{
  // define stopwatch
  TickTock stopwatch;
  stopwatch.tick(); // start stopwatch
  
  // ants walk on a table
  float number_of_ants[356][356];
  float new_number_of_ants[356][356];
  float velocity_of_ants[356][356];
  const int total_ants = 1010; // initial number of ants
  // initialize
  for (int i=0;i<356;i++) {
    for (int j=0;j<356;j++) {
      velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/3560)+1);
    }
  }
  int n = 0;
  float z = 0;
  for (int i=0;i<356;i++) {
    for (int j=0;j<356;j++) {
      number_of_ants[i][j] = 0.0;
    }
  }
  while (n < total_ants) {
    for (int i=0;i<356;i++) {
      for (int j=0;j<356;j++) {
	z += sin(0.3*(i+j));
	if (z>1 and n!=total_ants) {
	  number_of_ants[i][j] += 1;
	  n += 1;
	}
      }
    }
  }
  
  double timestring1 = stopwatch.silent_tock();
  std::cout << "Initialization complete: " << timestring1 << " sec elapsed" << std::endl;
  
  // run simulation
  for (int t = 0; t < 40; t++) {
    float totants = 0.0;
    for (int i=0;i<356;i++) {
      for (int j=0;j<356;j++) {
	totants += number_of_ants[i][j];
      }
    }
    double timestep = stopwatch.silent_tock();
    std::cout << t<< " " << totants << "\t" << timestep << std::endl;
    for (int i=0;i<356;i++) {
      for (int j=0;j<356;j++) {
	new_number_of_ants[i][j] = 0.0;
      }
    }
    stopwatch.tock("Time measurement after output step:");
    for (int i=0;i<356;i++) {
      for (int j=0;j<356;j++) {
	int di = 1.9*sin(velocity_of_ants[i][j]);
	int dj = 1.9*cos(velocity_of_ants[i][j]);
	int i2 = i + di;
	int j2 = j + dj;
	// some ants do not walk
	new_number_of_ants[i][j]+=0.8*number_of_ants[i][j];
	// the rest of the ants walk, but some fall of the table
	if (i2>=0 and i2<356 and j2>=0 and j2<356) {
	  new_number_of_ants[i2][j2]+=0.2*number_of_ants[i][j];
	}
      }
    }
    for (int i=0;i<356;i++) {
      for (int j=0;j<356;j++) {
	number_of_ants[i][j] = new_number_of_ants[i][j];
	totants += number_of_ants[i][j];
      }
    }
  }
  
  double timestring2 = stopwatch.silent_tock();
  std::cout << "Done! Total time elapsed: " << timestring2 << " sec" << std::endl;
  return 0;
}
 
