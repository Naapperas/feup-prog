#include <iostream>
#include <cmath>
#include <iomanip>

#define STEP 15

using namespace std;

int main(){

    cout << "ang\tsin\t\tcos\t\ttan" << endl;

    for (double i = 0; i <= 90; i += STEP){
        double ang = i * M_PI / 180;

        if(i == 90)
            cout << fixed << setprecision(0) << i << '\t' << fixed << setprecision(6) << 1 << "\t\t" << 0 << "\t\t" << "infinite" << endl;
        else
            cout << fixed << setprecision(0) << i << '\t' << fixed << setprecision(6) << sin(ang) << '\t' << cos(ang) << '\t' << tan(ang) << endl;
    }

    return 0;
}