#include <iostream>
#include "funcs.h"

int main(){
  std::cout<<minutesSinceMidnight({10, 30})<<" minutes"<<std::endl;
  std::cout<<minutesUntil( {10, 30}, {13, 40} )<<" minutes"<<std::endl;
  return 0;
}
