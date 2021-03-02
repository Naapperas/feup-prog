#include <iostream>
#include <cmath>

using namespace std;

class Point {
    
    private:
        int x;
        int y;

    public:
        Point() { }

        Point(int x, int y){
            this->x = x;
            this->y = y;
        }

        double distance(Point p){

            double dist;

            dist = pow(this->x - p.x, 2);
            dist += pow(this->y - p.y, 2);

            return sqrt(dist);

        }

    friend istream& operator>> (istream& in, Point& p);      
};

istream& operator>> (istream& in, Point& p){

    in >> p.x >> p.y;

    return in;
}

int main(){

    double a, b, c, s;

    Point A, B, C;

    cout << "Please input vertice coordinates in the for 'x y'" << endl;
    
    cout << "Vertice A: " << endl;
    cin >> A;

    cout << "Vertice B: " << endl;
    cin >> B;

    cout << "Vertice C: " << endl;
    cin >> C;


    a = A.distance(B);
    b = B.distance(C);
    c = C.distance(A);

    s = (a + b + c) / 2;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "The area of the triangle is " << area << endl;

    return 0;
}