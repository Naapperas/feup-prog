#include <iostream>
#include <chrono>

using namespace std;

int main(){

    srand(time(NULL));

    int n1 = rand() % 8 + 2, n2 = rand() % 8 + 2, correct = n1 * n2, answer;

    cout << "What is the result of " << n1 << " * " << n2 << "?" << endl;

    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

    cin >> answer;

    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

    auto elapsedTime = chrono::duration_cast<chrono::seconds>(t2 - t1).count();

    if (answer != correct) 
        cout << "Very bad!";
    else {
        if (elapsedTime < 5)
            cout << "Good";
        else if (elapsedTime >= 5 && elapsedTime <= 10)
            cout << "Satisfactory";
        else
            cout << "Insufficient";
    }
    cout << endl;

    return 0;
}