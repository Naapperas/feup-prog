// This is how I would have implemented the following exercise

#include <iostream>

using namespace std;

void reduceFraction(int &num, int &den);
unsigned int gcd(unsigned a, unsigned b);

// TODO: how to deal with fractions that have negative numerator and denominator values

struct fraction {
    private:
        int numerator, denominator;

    public:
        fraction(int numer, int denom) {

            if (denom == 0) {
                throw std::invalid_argument("Denominator cannot be 0");
            }

            this->numerator = numer;
            this->denominator = denom;
        }

        void reduce() {reduceFraction (numerator, denominator);}

    friend fraction operator+(fraction rhs, fraction lhs);
    friend fraction operator-(fraction rhs, fraction lhs);
    friend fraction operator*(fraction rhs, fraction lhs);
    friend fraction operator/(fraction rhs, fraction lhs);
    friend bool operator==(fraction frac, double d);
    friend bool operator==(fraction frac, int i);
    friend ostream& operator<<(ostream& out, fraction f);
    friend istream& operator>>(istream& in, fraction &f);

};

ostream& operator<<(ostream& out, fraction f) {
    cout << f.numerator << "/" << f.denominator;
    return out;
}

istream& operator>> (istream& in, fraction &f) {

    int num, den;
    char b;

    if (!in >> num) {
        // error
    }

    if (!in >> b || b != '/') {
        // error
    }

    if (!in >> den) {
        // error
    }

    in.clear();
    in.ignore(1000000, '\n');

    f = fraction(num, den);

    return in;
}

bool operator==(fraction f, double d) {
    f.reduce();
    return ((double) f.numerator) / f.denominator == d;
}

bool operator==(fraction f, int i) {
    f.reduce();
    return f.denominator == 1 && f.numerator == i; 
}

fraction operator+(fraction lhs, fraction rhs) {

    int den, num;

    den = rhs.denominator * lhs.denominator;
    num = (rhs.denominator * lhs.numerator) + (rhs.numerator * lhs.denominator);

    return fraction(num, den);
}

fraction operator-(fraction lhs, fraction rhs) {
    
    return lhs + fraction(-rhs.numerator, rhs.denominator);
    
    /* works, but version before looks cleaner
    fraction f;

    int den, num;

    den = rhs.denominator * lhs.denominator;
    num = (rhs.denominator * lhs.numerator) - (rhs.numerator * lhs.denominator);

    f = fraction(num, den);

    return f; */
}

fraction operator*(fraction lhs, fraction rhs) {

    int den, num;

    den = rhs.denominator * lhs.denominator;
    num = rhs.numerator * lhs.numerator;

    return fraction(num, den);
}

fraction operator/(fraction lhs, fraction rhs) {

    return lhs * fraction(rhs.denominator, rhs.numerator);
}

unsigned int gcd(unsigned a, unsigned b) {

    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;

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

void reduceFraction(int &num, int &den) {
    auto gcdNum = gcd(num, den);
    num /= gcdNum, den /= gcdNum;   
}

int main(){

    fraction f1 = fraction(-1, 2), f2 = fraction(1, 3), f3 = fraction(-1, -2), f4 = fraction(9, 3);

    cout << (f1 - f2) * f3 << endl;
    cout << (f4 == 3) << endl; 

    return 0;
}