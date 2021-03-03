#include <iostream>

using namespace std;

int main(){

    int a, b, c;

    int smallest, biggest, medium;

    cout << "Input 3 numbers." << endl;
    cin >> a >> b >> c;

    if (a > b && a > c) {
        biggest = a;
    } else if (b > a && b > c) {
        biggest = b;
    } else if (c > a && c > b) {
        biggest = c;
    }

    if (a < b && a < c) {
        smallest = a;
    } else if (b < a && b < c) {
        smallest = b;
    } else if (c < a && c < b) {
        smallest = c;
    }


    if ((a < b && a > c) || (a < c && a > b)) {
        medium = a;
    } else if ((b < a && b > c) || (b < c && b > a)) {
        medium = b;
    } else if ((c < a && c > b) || (c < b && c > a)) {
        medium = c;
    }

    cout << biggest << " " << medium << " " << smallest << endl;

    return 0;
}