#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) { return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); }

double area(double x1, double y1, double x2, double y2, double x3, double y3) {

    double distA = distance(x1, y1, x2, y2);
    double distB = distance(x2, y2, x3, y3);
    double distC = distance(x3, y3, x1, y1);

    double semiPer = (distA + distB + distC) / 2;

    return sqrt(semiPer * (semiPer - distA) * (semiPer - distB) * (semiPer - distC));    

 }

int main() {

    double x1, y1, x2, y2, x3, y3;

    cout << "Write coordinates of the first point: ";
    cin >> x1 >> y1;

    cout << "Write coordinates of the second point: ";
    cin >> x2 >> y2;

    cout << "Write coordinates of the third point: ";
    cin >> x3 >> y3;

    cout << "Area of the triangle is " << area(x1, y1, x2, y2, x3, y3) << endl;

    return 0;
}