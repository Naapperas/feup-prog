#include <iostream>
#include <chrono>
#include <unistd.h>

using namespace std;

time_t timeElapsed() {

    static chrono::high_resolution_clock::time_point first = chrono::high_resolution_clock::time_point::min();  

    chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
    if (first == chrono::high_resolution_clock::time_point::min()) {
        first = now;
        return 0;
    }

    return chrono::duration_cast<chrono::seconds>(now - first).count();
}

int main(){

    cout << "Running" << endl;

    timeElapsed();

    sleep(10);

    cout << timeElapsed() << endl;

    sleep(1);

    cout << timeElapsed() << endl;

    sleep(5);

    cout << timeElapsed() << endl;

    return 0;
}