/*
#ifndef _TIME_
#define _TIME_

#include <string>
#define HOUR_SEC 3600
#define MIN_SEC 60
using namespace std;

class Time
{
public:
    Time();
    Time(const int hour,const int min,const int sec);
    void SetHour(const int hour);
    void SetMin(const int min);
    void SetSec(const int sec);
    int GetHour();
    int GetMin();
    int GetSec();
    string ShowTime();
    int CalSec();
    bool operator<=(const Time& timeObj);//추가
    bool operator>=(const Time& timeObj);//추가
private:
    int hour, min, sec;
    int t_sec;
};

#endif // TIME_H
*/
/*
#ifndef _TIME_
#define _TIME_
#include <string>
#define HOUR_SEC 3600
#define MIN_SEC 60
using namespace std;

class Time
{
public:
    Time();
    Time(const int hour, const int min, const int sec);

    void SetHour(const int hour);
    void SetMin(const int min);
    void SetSec(const int sec);

    int GetHour() const;
    int GetMin() const;
    int GetSec() const;

    string ShowTime() const;
    int CalSec();

    bool operator<=(const Time& timeObj) const;
    bool operator>=(const Time& timeObj) const;

private:
    int hour, min, sec;
    int t_sec;
};

#endif // TIME_H
*/

