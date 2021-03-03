#include <iostream>

using namespace std;

int main(){

    int a, b, c;

    int smallest, biggest;

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

    cout << "Biggest number: "<< biggest << "; Smallest number: " << smallest << endl;

    return 0;
}