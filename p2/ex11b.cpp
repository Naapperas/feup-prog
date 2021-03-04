#include <iostream>

using namespace std;

unsigned long long factorial(unsigned long num) {
    if (num <= 1) 
        return 1;
    else
        return num * factorial(num-1);
}

int main() {

    int numTerms;
    double res = 0;

    cout << "How many terms do you want to sum? ";
    cin >> numTerms;

    for (int i = 0; i < numTerms; i++)
        res += 1.0 / factorial(i);

    cout << "The approximation is " << res << endl;

    return 0;
}