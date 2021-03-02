#include <iostream>

using namespace std;

int main(){

    double a, b, c;
    double mean;

    cout << "Please input 3 numbers" << endl;
    
    cout << "A ?";
    cin >> a;

    cout << "B ?";
    cin >> b;

    cout << "C ?";
    cin >> c;

    mean = (a + b + c) / 3.0;

    cout << "mean\t\t= " << mean << endl;
    cout << "A - mean\t= " << a - mean << endl;
    cout << "B - mean\t= " << b - mean << endl;
    cout << "C - mean\t= " << c - mean << endl;

    return 0;
}