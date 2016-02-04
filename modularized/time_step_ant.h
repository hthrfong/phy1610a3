// time_step_ant.h
#ifndef TIME_STEP_ANT_H
#define TIME_STEP_ANT_H

#include <rarray>

void time_step_ant(int arr, float amp, float tot, float frac, \
		   rarray<float,2> &a, rarray<float,2> &b, rarray<float,2> &c);

#endif
