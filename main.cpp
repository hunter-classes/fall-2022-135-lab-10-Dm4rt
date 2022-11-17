#include <iostream>
#include "funcs.h"

int main(){
  std::cout<<minutesSinceMidnight({10, 30})<<" minutes"<<std::endl;
  std::cout<<minutesUntil( {10, 30}, {13, 40} )<<" minutes"<<std::endl;

  Time addedTime = addMinutes({8,10},75);
  std::cout<<addedTime.h<<":"<<addedTime.m<<std::endl;
  return 0;
}
