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

    unsigned long cont;
    unsigned long num;

    while (cont > 0) {
        if (isPrime(cont)) {
            num = cont;
            cout << num << endl;
        }

        cont ++;
    }
    
    cout << num << endl;

    return 0;
}