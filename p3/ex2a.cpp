#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num){

    if (num < 2)
        return false;

    if (num == 2)
        return true;

    for (int i = 2; i < sqrt(num) + 1; i++)
        if (num % i == 0)
            return false;

    return true;
}

int main(){

    long long num;

    cout << "Write a random positive number: ";
    cin >> num;

    cout << num << " is " << (isPrime(num) ? "prime" : "not prime") << "." << endl;

    return 0;
}