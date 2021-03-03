#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    int step, min, max;

    cout << "What are the min, max, and step values? ";
    cin >> min >> max >> step;

    cout << "ang\tsin\tcos\ttan" << endl;

    for (int i = min; i <= max; i += step){
        double ang = i * M_PI / 180;

        if ((i - 90) % 180 == 0)
            cout << i << '\t' << 1 << '\t' << 0 << '\t' << "infinite" << endl;
        else
            cout << setprecision(3) << i << '\t' << sin(ang) << '\t' << cos(ang) << '\t' << tan(ang) << endl;
    }

    return 0;
}