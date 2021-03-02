#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int radius;
    double density;

    cout << "Sphere radius(m)): ";
    cin >> radius;

    cout << "Sphere density(Kg/m^³): ";
    cin >> density;

    cout << "Sphere mass is equal to: " << (4/3) * density * pow(radius, 3) * M_PI << endl;

    return 0;
}