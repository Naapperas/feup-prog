#include <iostream>
#include <cmath>

using namespace std;

double round(double x, unsigned n) {

    double result;

    result = floor(x * pow(10, n) + 0.5) / pow(10, n);

    return result;
}

int main(){

    double d;
    int n;

    cout << "Write a double and the precision you want: ";
    cin >> d >> n;

    cout << "The number rounded up to " << n << " places is " << round(d, n) << "." << endl;

    return 0;
}