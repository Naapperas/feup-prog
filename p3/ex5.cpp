#include <iostream>

using namespace std;

unsigned int gcd(unsigned a, unsigned b) {

    if (a == b) 
        return a;
    
    if (a == 0) 
        return b;
    else if (b == 0) 
        return a;

    if (a < b)
        return gcd(b-a, a);
    else if (b < a)
        return gcd(a-b, b);

    return -1; // in case there is none
}

void gcd(unsigned a, unsigned b, unsigned int* result) {
    (*result) = gcd(a, b);
}

int main() {

    unsigned int i;

    gcd(122, 61, &i);

    cout << i << endl;

    return 0;
}