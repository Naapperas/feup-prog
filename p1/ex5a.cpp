#include <iostream>

using namespace std;

class Time {
    private:
        int day;
        int hour;
        int minute;
        int second;

    public:
        Time() {}

        Time(int h, int m, int s, int d = 0) {
            this->hour = h;
            this->minute = m;
            this->second = s;
            this->day = d;
        }

    friend ostream& operator<< (ostream& out, Time t);
    friend Time operator+ (Time lhs, Time rhs);
};

Time operator+ (Time lhs, Time rhs) {

    Time t;

    int day = 0, hour = 0, minute = 0, second;

    second = lhs.second + rhs.second;

    minute += second / 60;
    second %= 60;

    minute += lhs.minute + rhs.minute;

    hour += minute / 60;
    minute %= 60;
    
    hour += lhs.hour + rhs.hour;

    day += hour / 24;
    hour %= 24;

    t = Time(hour, minute, second, day);

    return t;
}

ostream& operator<< (ostream& out, Time t) {

    if(t.day)
        out << t.day << " day, ";
    
    out << t.hour << " hours, " << t.minute << " minutes and  " << t.second << " seconds.";
    return out;
}

int main() {

    int h, m, s;

    cout << "Time1 (hours minutes seconds) ? ";
    cin >> h >> m >> s;
    Time t1 = Time(h, m, s);

    cout << "Time2 (hours minutes seconds) ? ";
    cin >> h >> m >> s;
    Time t2 = Time(h, m, s);

    cout << "Time1 + Time2 = " << t1 + t2 << endl;

    return 0;
}