#include <iostream>
#include <limits>

using namespace std;

bool readInt(int &i) {

    cin >> i;

    bool flag = !(cin.bad() || cin.peek() != '\n');

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return flag;

}

int main(){

    int n;

    cout << "Write a number: ";

    bool status = readInt(n);

    cout << "Input given " << (status ? "was" : "was not") << " a number." << endl;

    return 0;
}