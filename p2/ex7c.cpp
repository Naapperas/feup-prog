#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num);

int main(){

    int num = 0, cont = 0;

    while (true) {
        if (cont == 100)
            break;

        if(isPrime(num)) {
            cout << num << endl;
            cont ++;
        }
        num++;
    } 

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