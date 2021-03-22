#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Reads nElems elements from the console and stores them in the array.
 * 
 * @param a the array to store numbers in
 * @param nElems the number of elements to store
 */
void readVector(vector<int> &a, istream &in) {

    while (!in.eof()) {
        int j;
        if (in >> j) // mid-loop check for EOF
            a.push_back(j);
    }

    in.clear();
    in.ignore(100000, '\n');
}

/**
 * @brief Finds a value in the given array, or -1 if it doesn't exist
 * 
 * @param a the array to searh the element in
 * @param nElems the number of elements in the array
 * @param value the value to search for
 * @param pos1 the initial position to search
 * @param pos2 the final position to search
 * @return int the index of the element in the array, or -1 if it doesn't exist
 */
int findValueInVector(const vector<int> &a, size_t nElems, int value, size_t pos1, size_t pos2) {

    for (int i = pos1; i < pos2 && (i - pos1) < nElems; i++)
        if (a.at(i) == value)
            return i; 

    return -1;
}

/**
 * @brief Finds all the indices of the given value in the array.
 * 
 * @param a the array to search in
 * @param nElems the number of elements to search for
 * @param value the value to search for
 * @param pos1 the initial position to search for
 * @param pos2 the last position to search for
 * @param index the array of found indices
 * @return int the number of elements in index
 */
int findMultValueInVector(const vector<int> &a, size_t nElems, int value, size_t pos1, size_t pos2, vector<size_t> &index) {

    int j = 0;

    int idx = findValueInVector(a, nElems, value, pos1, pos2);

    if (idx != -1) {
        index.push_back(idx);
        j++;
        
        while (idx != -1) {
            idx = findValueInVector(a, nElems, value, idx + 1, pos2);

            if (idx == -1) break;

            index.push_back(idx);
            j++;
            
        }
    }

    return j;
}

int main(){

    int nElems;

    cout << "What is the number of elements you want to read? ";
    cin >> nElems;

    int value;

    cout << "Input a number to search from the array: ";
    cin >> value;

    vector<int> a;
    vector<size_t> index; // index has AT MOST nElems elements, so we can initialize this way
    readVector(a, cin);

    int numOccur = findMultValueInVector(a, a.size(), value, 0, a.size(), index);

    if (numOccur == 0) {
        cout << value << " not found in the array." << endl;
    } else {
        cout << value << " was found " << numOccur << " times in the array at indices: " << endl;
        for (size_t i = 0; i < numOccur; i++) {
            cout << index[i] << " ";
        } 
    }
    cout << endl;
    return 0;
}