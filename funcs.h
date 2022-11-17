#pragma once
#include <string>

class Time { 
public:
    int h;
    int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
  std::string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//FUNCTIONS
std::string getTime(Time time);
std::string getMovie(Movie mv);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
std::string getTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); 
