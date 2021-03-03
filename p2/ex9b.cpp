#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(unsigned int num){

    if(num == 0) return true;

    int numDigits = floor(log10(num)) + 1;

    if (numDigits == 1) return true; 

    if(num % 10 == num / (int) pow(10, numDigits - 1)){
        num %= (int) pow(10, numDigits - 1);
        num /= 10;
        return isPalindrome(num);
    } else return false;

    return false;
}

int main(){

    unsigned int num;

    cout << "Write an integer: ";
    cin >> num; 
    
    cout << num << (isPalindrome(num) ? " is " : " is not ") << "a palindrome." << endl;

    return 0;
}