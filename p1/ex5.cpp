#include <iostream>

using namespace std;

class Time
{
    private:
        int day = 0;
        int hour;
        int minute;
        int second;

    public:
        Time() {}

        Time(int h, int m, int s){
            this->hour = h;
            this->minute = m;
            this->second = s;
        }

        int getHour() { return this->hour; }
        int getMinute() { return this->minute; }
        int getSecond() { return this->second; }

    friend ostream& operator<< (ostream& out, Time t);
    friend Time operator+ (Time lhs, Time rhs);
};

Time operator+ (Time lhs, Time rhs){

    Time t;

    int day, hour, minute, second;

    // insert logic here

    return t;
}

ostream& operator<< (ostream& out, Time t) {
    if(t.day)
        out << "Day: " << t.day;
    out << "Hours: " << t.hour << "; Minutes: " << t.minute << "; Seconds: " << t.second;
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

    cout << "Time 1: " << t1 << endl << "Time 2: " << t2 << endl;

    return 0;
}