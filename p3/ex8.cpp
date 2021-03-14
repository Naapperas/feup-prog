#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>

using namespace std;

/* struct fraction {
    private:
        int numerator, denominator;

    fraction(int numer, int denom) {
        this->numerator = numer;
        this->denominator = denom;
    }

    friend fraction operator+(fraction rhs, fraction lhs);
    friend fraction operator-(fraction rhs, fraction lhs);
    friend fraction operator*(fraction rhs, fraction lhs);
    friend fraction operator/(fraction rhs, fraction lhs);

}; */

bool readFraction(int &num, int &den);
void reduceFraction(int &num, int &den);
unsigned int gcd(unsigned a, unsigned b);
void addFraction(int num1, int den1, int num2, int den2, int &num, int &den);
void subtractFraction(int num1, int den1, int num2, int den2, int &num, int &den);
void multiplyFraction(int num1, int den1, int num2, int den2, int &num, int &den);
void divideFraction(int num1, int den1, int num2, int den2, int &num, int &den);

int main(){

    int i, j;

    readFraction(i, j);

    cout << i << "/" << j << endl;

    reduceFraction(i, j);

    cout << i << "/" << j << endl;

    subtractFraction(1, 2, 1, 3, i, j); // 1/6

    cout << i << "/" << j << endl;

    return 0;
}

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

bool readFraction(int &num, int &den) {

    string input;
    getline(cin, input);

    string tmp = ""; // remove whitespaces
    for (char c : input) {
        if (c == ' ') continue;
        tmp += c;
    }

    input = tmp;

    size_t opIndex = input.find('/');

    if (opIndex == string::npos) { // couldn't find '/' in input
        num = den = 0;
        return false;
    }
    string op1 = input.substr(0, opIndex), op2 = input.substr(opIndex + 1, input.size() - opIndex);

    for (char c : op1)
        if (!(c >= '0' && c <= '9')) { // op1 contains non-numerical characters
            num = den = 0;
            return false;
        }

    for (char c : op2)
        if (!(c >= '0' && c <= '9')) { // op2 contains non-numerical characters
            num = den = 0;
            return false;
        }

    num = stoi(op1), den = stoi(op2);

    return true;
}

void reduceFraction(int &num, int &den) {
    auto gcdNum = gcd(num, den);
    num /= gcdNum, den /= gcdNum;   
}

void addFraction(int num1, int den1, int num2, int den2, int &num, int &den) {

    den = den1 * den2;
    num = num1 * den2 + num2 * den1;

    reduceFraction(num,den);

}

void subtractFraction(int num1, int den1, int num2, int den2, int &num, int &den) {

    den = den1 * den2;
    num = num1 * den2 - num2 * den1;

    reduceFraction(num,den);

}

void multiplyFraction(int num1, int den1, int num2, int den2, int &num, int &den) {

    den = den1 * den2;
    num = num1 * num2;

    reduceFraction(num, den);

}

void divideFraction(int num1, int den1, int num2, int den2, int &num, int &den) {


    den = den1 * num2;
    num = num1 * den2;

    reduceFraction(num, den);


}