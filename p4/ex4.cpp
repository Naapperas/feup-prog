#include <iostream>
#include <vector>

using namespace std;

bool inVector(const vector<int> &v, int value) {

    for (int a : v)
        if (a == value)
            return true;

    return false;
}

/**
 * @brief Searches for the value in the vector and returns its index or -1 if is not found. 
 * 
 * @param v the vector to search in
 * @param value the value to search for
 * @return int the index of value or -1
 */
int binarySearch(const vector<int> &v, int value) {

    if (!inVector(v, value))
        return -1;

    int low = 0;
    int high = v.size() - 1;

    do {
        int middle = (low + high) / 2;

        if(v.at(middle) == value)
            return middle;
        else
            if (v.at(middle) > value)
                high = middle - 1;
            else
                low = middle + 1;
        
    } while (low < high);

    return -1;
}


int main(){

    vector<int> a = {1, 2, 3, 4};

    cout << binarySearch(a, 5) << endl;

    return 0;
}