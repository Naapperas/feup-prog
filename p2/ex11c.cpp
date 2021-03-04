#include <iostream>
#include <cmath>

using namespace std;

unsigned long long factorial(unsigned long num) {
    if (num <= 1) 
        return 1;
    else
        return num * factorial(num-1);
}

int main() {

    int numTerms;
    double res = 0, num;

    cout << "Input a number: ";
    cin >> num;

    cout << "How many terms do you want to sum? ";
    cin >> numTerms;

    for (int i = 0; i < numTerms; i++)
        res += pow(-num, i) / factorial(i);

    cout << "The approximation is " << res << endl;

    return 0;
}