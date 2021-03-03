#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b;

    cout << "Enter two numbers." << endl;
    cin >> a >> b;

    if (a > INT_MAX - b) {
        cout << "sum overflow" << endl;
    } else if (a < INT_MIN + b) {
        cout << "sum underflow" << endl;
    } else {
        cout << a + b << endl;
    }

    return 0;
}