#include <iostream>
#include <cmath>

using namespace std;

#define ARR_SIZE 100

int main() {

    int nums[ARR_SIZE];
    int numElems, sum;

    cout << "What is the number of elements? ";
    cin >> numElems;

    if (numElems > ARR_SIZE) {
        cout << "Too many elements.";
        return -1;
    }

    cout << "Please enter " << numElems << " numbers:" << endl;

    for (int i = 0; i < numElems; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    double mean = ((double) sum) / numElems;

    int smallest = 9999999, largest = -9999999;
    for (int i = 0; i < numElems; i++){
        int num = nums[i];
        if (num < smallest)
            smallest = num;
        else if (num > largest)
            largest = num;
    }

    double stdDev = 0;

    for (int i = 0; i < numElems; i++)
        stdDev += pow(nums[i] - mean, 2);
    
    stdDev /= (double) (numElems - 1);

    cout << "Sum: " << sum << "; Mean: " << mean << "; Standard deviation: " << sqrt(stdDev) << "; Lowest number: " << smallest << "; Biggeste number: " << largest << ";" << endl;

    return 0;
}