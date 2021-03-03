#include <iostream>

using namespace std;

int main(){

    double weight, price;

    cout << "What is the weight of the merchandise in grams? ";
    cin >> weight;

    if (weight < 0) {
        cout << "Can't have negative weights";
        return -1;
    }

    if (weight <= 500){
        price = 5;
    } else if (weight > 500 && weight <= 1000) {
        price = 5 + 1.5 * ((weight - 500) / 100);
    } else {
        price = 12.5 + 2.5 * ((weight - 1000) / 250);
    }

    cout << "The cost to transport the merchandise is " << price << " euros." << endl;

    return 0;
}