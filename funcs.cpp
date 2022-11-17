#include <iostream>
#include "funcs.h"

int minutesSinceMidnight(Time time){
  int total = time.h*60;
  total = total + time.m;
  return total;
}

int minutesUntil(Time earlier, Time later){
  int dist = minutesSinceMidnight(later)-minutesSinceMidnight(earlier);
  return dist;
}
