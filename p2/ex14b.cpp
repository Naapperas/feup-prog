#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int decPlaces(double num) {

    if (abs(num) > 1) {
        cout << "Number is bigger than 1." << endl;
        return -1;
    }

    int i = 0;

    while (abs(num *= 10) < 1)
        i++;

    return i + 1;

}

int main(){

    int nMaxIter;
    double n, delta, result = 0, dif = 0, rq = 1, rqn;

    cout << "Please input a number to calculate the square root of: ";
    cin >> n;

    cout << "Please input the max deviation allowed: ";
    cin >> delta;

    cout << "Please input the maximum number of iterations allowed: ";
    cin >> nMaxIter;

    int iters = 0;

    while (iters++ < nMaxIter && dif < delta) {

        rqn = (rq + n / rq) / 2;

        dif = n - rqn * rqn;

        rq = rqn;

    }

    cout << fixed << setprecision(decPlaces(delta)) << "Heron: " << rq << "; C sqrt(): " << sqrt(n) << endl;

    return 0;
}