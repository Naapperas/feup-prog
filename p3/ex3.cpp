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

double heronSqrt(double n, double delta, int maxIters) {

    double rq = 1, rqn, dif = 0;

    int iters = 0;

    while (iters++ < maxIters && dif < delta) {

        rqn = (rq + n / rq) / 2;

        dif = n - rqn * rqn;

        rq = rqn;

    }

    return rq;
}

int main(){

    int nMaxIter;
    double n, delta;

    cout << "Please input a number to calculate the square root of: ";
    cin >> n;

    cout << "Please input the max deviation allowed: ";
    cin >> delta;

    cout << "Please input the maximum number of iterations allowed: ";
    cin >> nMaxIter;

    int iters = 0;

    double rq = heronSqrt(n, delta, nMaxIter);

    cout << fixed << setprecision(decPlaces(delta)) << "Heron: " << rq << "; C sqrt(): " << sqrt(n) << endl;

    return 0;
}