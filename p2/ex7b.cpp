#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num);

int main(){

    for (int i = 0; i < 1000; i++)
        if (isPrime(i))
            cout << i << endl;

    return 0;
}

bool isPrime(long long num){

    if (num < 2) {
        return false;
    }

    if (num == 2) {
        return true;
    }

    for (int i = 2; i < sqrt(num) + 1; i++){
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}