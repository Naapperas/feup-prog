#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int numTerms;
    double res = 0;

    cout << "How many terms do you want to sum? ";
    cin >> numTerms;

    for (int i = 1; i <= numTerms; i++)
        res += pow(-1, i-1) / (2 * i - 1);

    cout << "The approximations is " << 4 * res << endl;

    return 0;
}