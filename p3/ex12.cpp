#include <iostream>
#include <cmath>

using namespace std;

class Point {
    
    private:
        int x;
        int y;

    public:
        Point(int _x, int _y){
            this->x = _x;
            this->y = _y;
        }

        double distance(Point p){

            double dist;

            dist = pow(this->x - p.x, 2);
            dist += pow(this->y - p.y, 2);

            return sqrt(dist);
        }

    friend double area(Point v1, Point v2);  
};

double area(double radius) {
    return pow(radius, 2) * M_PI;
}

double area(Point A, Point B, Point C) {

    double a, b, c;

    a = A.distance(B);
    b = B.distance(C);
    c = C.distance(A);

    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(Point v1, Point v2) {
    return abs(v1.x - v2.x)*abs(v2.y - v1.y);
}

int main(){

    double radius;
    cout << "Input circle radius: ";
    cin >> radius;

    cout << "Circle area: " << area(radius) << endl;

    return 0;
}