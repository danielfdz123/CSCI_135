//Daniel Andres Fernandez
//danitl.fernandez16@myhunter.cuny.edu
//October 28, 2022
//Lab 10b

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Time {
public:
    int h; 
    int m;
};

int minutesSinceMidnight(Time time)
{
    int final = 0;
    final += time.m;
    final += time.h * 60;
    return final;
}

int minutesUntil(Time earlier, Time later)
{
    int total = 0;
    total += later.m - earlier.m;
    total += (later.h - earlier.h) * 60;
    return total;
}

Time addMinutes(Time time, int min) 
{
    Time newTime;
    newTime.h = time.h + (time.m + min) / 60;
    newTime.m = (time.m + min) % 60;
    return newTime;
}

int main()
{
    Time time, addedTime;
    cout << "Enter first time: ";
    cin >> time.h >> time.m;
    double add;
    cout << "Enter added time: ";
    cin >> add;
    addedTime = addMinutes(time, add);
    cout << addedTime.h << ":" << addedTime.m << "\n";
}
