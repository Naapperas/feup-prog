#include <iostream>
#include <cmath>

using namespace std;

unsigned long long factorial(unsigned long num) {
    if (num <= 1) 
        return 1;
    else
        return num * factorial(num-1);
}

int main(){

    double res = 0, precision, oldRes = 9999999999;

    cout << "What precision do you want? ";
    cin >> precision;
    
    double i = 0;

    while (abs(oldRes - res) > abs(precision)){
        oldRes = res;
        res += 1.0 / factorial(i);
        i++;
    }
        
    cout << "The approximations is " << res << endl;

    return 0;
}