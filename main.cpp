#include <iostream>
#include "funcs.h"

int main(){
  std::cout<<minutesSinceMidnight({10, 30})<<" minutes"<<std::endl;
  std::cout<<minutesUntil( {10, 30}, {13, 40} )<<" minutes"<<std::endl;

  Time addedTime = addMinutes({8,10},75);
  std::string goodTime = getTime(addedTime);

  std::cout<<goodTime<<std::endl;

  Time movTime = {2,25};
  Movie mov = {"Star Wars",ACTION,105};
  TimeSlot movSlot = {mov,movTime};

  std::cout<<getTimeSlot(movSlot)<<std::endl;

  Movie nextMov = {"Indiana Jones", ACTION,115};
  TimeSlot movAfter = scheduleAfter(movSlot, nextMov);
  std::cout<<getTimeSlot(movAfter)<<std::endl;

  Time etMovTime = {4,5};
  Movie etMov = {"ET", THRILLER, 114};
  TimeSlot etSlot = {etMov, etMovTime};
  std::cout<<getTimeSlot(etSlot)<<std::endl;
  std::cout<<timeOverlap(etSlot, movSlot)<<std::endl;
  std::cout<<timeOverlap(movAfter, movSlot)<<std::endl;
  return 0;
}
