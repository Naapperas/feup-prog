#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, c;

    cout << "Solution of Ax^2 + Bx + C = 0" << endl << "Insert the coefficients ( A B C ): ";
    cin >> a >> b >> c;

    double binDescr = pow(b, 2) - 4 * a * c;

    cout << "The equation has 2 ";

    if (binDescr == 0) {
        cout << "equal real roots: " << -b / (2 * a) << endl;
    } else if (binDescr > 0) {
        cout << "different real roots: " << (-b - sqrt(binDescr)) / (2 * a) << " and " << (-b + sqrt(binDescr)) / (2 * a) << endl; 
    } else {
        cout << "different complex roots: " << -b / (2 * a) << " - i * " << sqrt(abs(binDescr)) / (2 * a) << " and " <<  -b / (2 * a) << " + i * " << sqrt(abs(binDescr)) / (2 * a) << endl;
    }


    return 0;
}