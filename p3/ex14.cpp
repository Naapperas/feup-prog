#include <iostream>

using namespace std;

double integrateTR(double f(double), double a, double b, int n) {

    double h = (b - a) / n;

    double res = 0;

    for (auto i = 0; i < n; i++)
        res += ((h / 2) * (f(a + ((i - 1) * h)) + f(a + i * h)));

    return res;

}

double g(double x) { return x * x; }

int main(){

    cout << integrateTR(g, 0, 10, 1000000) << endl;

    return 0;
}