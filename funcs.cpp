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

Time addMinutes(Time time0, int min){
  Time newTime;
  int newMin = time0.h*60;
  newMin = newMin + time0.m;
  newMin = newMin + min;
  int newHour = newMin/60;
  newMin = newMin%60;
  newTime.h = newHour;
  newTime.m = newMin;

  return newTime;
}
