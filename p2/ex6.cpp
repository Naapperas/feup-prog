#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double n, q, j;

    cout << "Write the values of n, q, and j" << endl;
    cin >> n >> q >> j;
    
    cout << "The user can withdrawl " << q * pow((1 + (j / 100)), n) << " euros." << endl;

    return 0;
}