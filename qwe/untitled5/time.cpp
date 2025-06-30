/*
#include "time.h"

using namespace std;

int main(){
    Time t1(7,30,20);
    cout << t1.ShowTime() << endl;
    cout << "s: " << t1.CalSec() << endl;

    Time t2(4,50,23);
    if(t1>=t2){
    cout << t1.ShowTime()<< " " << t2.ShowTime() << " ";
    cout << endl;
    }else{
        cout << t2.ShowTime()<< " " << t1.ShowTime() << " ";
        cout << endl;
    }

    if(t1<=t2){
        cout << t2.ShowTime()<< " " << t1.ShowTime() << " ";
        cout << endl;
    }else{
        cout << t1.ShowTime()<< " " << t2.ShowTime() << " ";
        cout << endl;
    }

    return 0;
}

int Time::CalSec() {
    t_sec = hour * HOUR_SEC + min * MIN_SEC + sec;
    return t_sec;
}

bool Time::operator<=(Time timeObj)
{
    this->CalSec();
    timeObj.CalSec();

    if(this->t_sec<=timeObj.t_sec)
        return true;
    else
        return false;
}

bool Time::operator>=(Time timeObj)
{
    this->CalSec();
    timeObj.CalSec();

    if(this->t_sec>=timeObj.t_sec)
        return true;
    else
        return false;
}*/

/*
#include "Time.h"
#include <iomanip>

Time::Time() : hour(0), min(0), sec(0), t_sec(0) {}

Time::Time(const int hour, const int min, const int sec)
    : hour(hour), min(min), sec(sec) {
    CalSec();
}

void Time::SetHour(const int h) { hour = h; CalSec(); }
void Time::SetMin(const int m) { min = m; CalSec(); }
void Time::SetSec(const int s) { sec = s; CalSec(); }

int Time::GetHour() const { return hour; }
int Time::GetMin() const { return min; }
int Time::GetSec() const { return sec; }

int Time::CalSec() {
    t_sec = hour * HOUR_SEC + min * MIN_SEC + sec;
    return t_sec;
}

string Time::ShowTime() const {
    ostringstream oss;
    oss << setw(2) << setfill('0') << hour << "시 "
        << setw(2) << setfill('0') << min << "분 "
        << setw(2) << setfill('0') << sec << "초";
    return oss.str();
}

bool Time::operator<=(const Time& timeObj) const {
    return this->hour * HOUR_SEC + this->min * MIN_SEC + this->sec <=
           timeObj.hour * HOUR_SEC + timeObj.min * MIN_SEC + timeObj.sec;
}

bool Time::operator>=(const Time& timeObj) const {
    return this->hour * HOUR_SEC + this->min * MIN_SEC + this->sec >=
           timeObj.hour * HOUR_SEC + timeObj.min * MIN_SEC + timeObj.sec;
}*/



