#include <iostream>

using namespace std;

unsigned int gcd(unsigned a, unsigned b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main(){

    int a, b;

    cout << "Input 2 numbers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;

    return 0;
}