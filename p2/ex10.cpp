#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long unsigned num){

    if (num < 2) return false;

    if (num == 2) return true;

    for (int i = 2; i < sqrt(num) + 1; i++)
        if (num % i == 0)
            return false;

    return true;
}

int main(){

    int num;

    cout << "Please input a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Prime numbers can't be negative" << endl;
        return -1;
    }

    if (num == 0 or num == 1) {
        cout << num << endl;
        return 0;
    }

    int primeDiv = 2;

    while (num > 1) {
        if (isPrime(primeDiv))
            while (num % primeDiv == 0) {
                cout << primeDiv;
                if (num != primeDiv)
                    cout << "x";
                num /= primeDiv;
            }
        primeDiv++;
    }

    cout << endl;

    return 0;
}
