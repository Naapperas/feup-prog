#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double res = 0, precision, oldRes = 9999999999;

    cout << "What precision do you want? ";
    cin >> precision;
    
    double i = 1;

    while (abs(oldRes - res) > abs(precision)){
        oldRes = res;
        res += pow(-1, i-1) / (2.0 * i - 1.0);
        i++;
    }
        
    cout << "The approximations is " << 4 * res << endl;

    return 0;
}