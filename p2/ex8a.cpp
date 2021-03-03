#include <iostream>
#include <cmath>
#include <iomanip>

#define STEP 15

using namespace std;

int main(){

    cout << "ang\tsin\tcos\ttan" << endl;

    for (double i = 0; i <= 90; i += STEP){
        double ang = i * M_PI / 180;

        if(i == 90)
            cout << i << '\t' << 1 << '\t' << 0 << '\t' << "infinite" << endl;
        else
            cout << setprecision(3) << i << '\t' << sin(ang) << '\t' << cos(ang) << '\t' << tan(ang) << endl;
    }

    return 0;
}