//Daniel Andres Fernandez
//danitl.fernandez16@myhunter.cuny.edu
//October 28, 2022
//Lab 10a

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

int main()
{
    Time time1, time2;
    cout << "Enter first time: ";
    cin >> time1.h >> time1.m;
    cout << "Enter second time: ";
    cin >> time2.h >> time2.m;
    cout << "These moments of time are X and Y minutes after midnight." << endl << "The interval between them is Z minutes.";
}