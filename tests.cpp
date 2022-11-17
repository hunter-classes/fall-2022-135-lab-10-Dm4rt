#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "funcs.h"


TEST_CASE("getTime"){
  Time time = {9,30};
  Time otherTime = {10,5};
  CHECK(getTime(time)=="9:30");
  CHECK(getTime(otherTime)=="10:05");
}

TEST_CASE("getMove"){
  Movie mov = {"Star Wars",ACTION,105};

  CHECK(getMovie(mov)=="Star Wars ACTION (105 min)");
}

TEST_CASE("minutesSinceMidnight"){
  Time time = {9,30};
  Time otherTime = {10,5};
  CHECK(minutesSinceMidnight(time)==570);
  CHECK(minutesSinceMidnight(otherTime)==605);
}

TEST_CASE("minutesUntil"){
  Time time = {9,30};
  Time otherTime = {10,5};
  CHECK(minutesUntil(time,otherTime)==35);
  CHECK(minutesUntil(otherTime,time)==-35);
}

TEST_CASE("addMinutes"){
  Time time = {9,30};
  Time newTime = addMinutes(time, 130);
  Time corTime = {11,40};
  CHECK(getTime(newTime)==getTime(corTime));
}

TEST_CASE("getTimeSlot"){
   Movie mov = {"Star Wars",ACTION,105};
   Time movTime = {2,25};
   CHECK(getTimeSlot({mov,movTime})=="Star Wars ACTION (105 min) [starts at 2:25, and ends by 4:10]");
}

TEST_CASE("scheduleAfter"){
  Movie mov = {"Star Wars",ACTION,105};
  Time movTime = {2,25};
  TimeSlot starWars = {mov,movTime};

  Movie nextMov = {"Indiana Jones", ACTION,115};
  TimeSlot indianaJones = scheduleAfter(starWars, nextMov);
  CHECK(minutesUntil(starWars.startTime,indianaJones.startTime)==starWars.movie.duration);
}

TEST_CASE("timeOverlap"){
  Movie mov = {"Star Wars",ACTION,105};
  Time movTime = {2,25};
  TimeSlot starWars = {mov,movTime};
  Movie nextMov = {"Indiana Jones", ACTION,115};
  Time etMovTime = {4,5};
  Movie etMov = {"ET", THRILLER, 114};
  TimeSlot etSlot = {etMov, etMovTime};
  TimeSlot indianaJones = scheduleAfter(starWars, nextMov);

  CHECK(timeOverlap(starWars,indianaJones)==false);
  CHECK(timeOverlap(starWars,etSlot)==true);
}
