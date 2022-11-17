#include <iostream>
#include <string>
#include <sstream>
#include "funcs.h"

std::string getTime(Time time) {
  std::stringstream hour;
  hour<<time.h;
  std::stringstream minutes;
  minutes<<time.m;
  std::string zero;
  if(time.m<10){
    zero="0";
  }
  else{
    zero="";
  }
  std::string formattedTime= hour.str() + ":" +zero+  minutes.str();
  return formattedTime;
}

std::string getMovie(Movie mv){
  std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::stringstream minutes;
    minutes<<mv.duration;
    std::string des=  mv.title + " " + g + " (" + minutes.str() + " min)";
    return des;
}

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

std::string getTimeSlot(TimeSlot ts){
  std::string description = "";
  description = description + getMovie(ts.movie);
  int endHour = ts.startTime.h;
  int endMinute = ts.startTime.m;
  int convMin = ts.movie.duration%60;
  int convHour = ts.movie.duration/60;

  endHour = endHour + convHour;
  endMinute = endMinute + convMin;

  endHour = endHour + endMinute/60;
  endMinute = endMinute%60;
  
  Time endTime = {endHour, endMinute};

  description = description + " [starts at " + getTime(ts.startTime) + ", and ends by " + getTime(endTime)+"]";
  return description;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  int hour = ts.startTime.h;
  int min = ts.startTime.m;

  int durHour = ts.movie.duration/60;
  int durMin = ts.movie.duration%60;

  hour += durHour;
  min += durMin;
  hour += min/60;
  min = min%60;

  TimeSlot nextTs = {nextMovie, {hour,min}};

  return nextTs;
  
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  TimeSlot lower;
  TimeSlot higher;

  if(minutesUntil(ts1.startTime,ts2.startTime)<0){
    lower=ts2;
    higher=ts1;
  }
  else if(minutesUntil(ts2.startTime,ts1.startTime)<0){
    lower=ts1;
    higher=ts2;
  }
  else{
    return true;
  }

  int timeBetween=minutesUntil(lower.startTime, higher.startTime);
  if(timeBetween<lower.movie.duration){
    return true;
  }
  else{
    return false;
  }

}
