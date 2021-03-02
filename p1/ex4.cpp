#include <iostream>

using namespace std;

int main() {

    int a, b, c, d, e, f;
    cout << "Input numbers for a, b, c, d, e, f." << endl;
    cin >> a >> b >> c >> d >> e >> f;

    double den = ((a*e) - (b*d));

    if (den == 0){
        cout << "Impossible system" << endl;
        return -1;
    }

    double num1 = ((c*e) - (b*f));
    double num2 = ((a*f) - (c*d));

    double x = num1 / den;
    double y = num2 / den;

    cout << "x = " << x << "; y = " << y << endl;

    return 0;
}