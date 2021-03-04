#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int i = 0;
    vector<int> nums;

    cout << "Enter a sequence of number separated by spaces. A '0' marks the end of the sequence" << endl;

    while (true) {
        int num;
        cin >> num;

        if (num == 0) break;

        nums.push_back(num);
    }

    int numElems = nums.size();

    int sum = 0, lowest = 9999999, highest = -99999999;

    for (auto &i : nums) {
        sum += i;
        if (i < lowest) lowest = i;
        else if (i > highest) highest = i;
    }

    double mean = ((double) sum) / numElems;

    double stdDev = 0;

    for (auto &i : nums)
        stdDev += pow(i - mean, 2);
    
    stdDev /= (double) (numElems - 1);

    cout << "Sum: " << sum << "; Mean: " << mean << "; Standard deviation: " << sqrt(stdDev) << "; Lowest number: " << lowest << "; Biggeste number: " << highest << ";" << endl;

    return 0;
}