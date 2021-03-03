#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long long num;
    
    cout << "Enter a number to check if it is prime: ";
    cin >> num;

    if (num < 2) {
        cout << num << " is not prime." << endl;
        return -1;
    }

    for (int i = 2; i < sqrt(num); i++){
        if (num % i == 0) {
            cout << num << " is not prime." << endl;
            return -1;
        }
    }

    cout << num << " is prime." << endl;

    return 0;
}