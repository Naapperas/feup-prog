#include <iostream>
#include <climits>

using namespace std;

unsigned long long factorial_ite(unsigned long num) {

    unsigned long long res = 1;

    for(int i = 1; i <= num; i++) {res *= i;}

    return res;
}

unsigned long long factorial_rec(unsigned long num) {
    if(num < 1) return 1;
    else return num * factorial_rec(num - 1);
}

int main(){

    unsigned long num;

    cout << "Input a number: ";
    cin >>num;

    cout << "Recursive: " << factorial_rec(num) << "; Iterative: " << factorial_ite(num) << endl;

    return 0;
}