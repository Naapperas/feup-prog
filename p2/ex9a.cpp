#include <iostream>

using namespace std;

bool isPalindrome(unsigned int num){

    if (num % 10 == num / 100)
        return true;

    return false;
}

int main(){

    unsigned int num;

    cout << "Write a three digit integer: ";
    cin >> num; 

    cout << num << (isPalindrome(num) ? " is " : " is not ") << "a plindrome." << endl;

    return 0;
}