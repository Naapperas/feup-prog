#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int sum = 0, smallest = 999999, largest = -999999;
    vector<int> nums;

    char c;

    int tmp = 0;
    while((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n') {

            if (tmp < smallest)
                smallest = tmp;
            else if (tmp > largest)
                largest = tmp;

            nums.push_back(tmp);
            sum += tmp;
            tmp = 0;
            continue;
        }

        if(c >= '0' && c <= '9') {
            tmp *= 10;
            tmp += (c - '0');
        }       

    }

    double mean = ((double) sum) / nums.size();

    double stdDev;

    for (auto &i : nums) {
        stdDev += pow(i - mean, 2);
    }

    stdDev /= (nums.size() - 1);

    cout << "Sum: " << sum << "; Mean: " << mean << "; Standard deviation: " << sqrt(stdDev) << "; Lowest number: " << smallest << "; Biggeste number: " << largest << ";" << endl;

    return 0;
}