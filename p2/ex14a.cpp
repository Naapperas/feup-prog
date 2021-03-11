#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int nMaxIter;
    double n, delta;
    double result = 0, dif = 0, rq = 1, rqn;

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

    cout << rq << endl;

    return 0;
}