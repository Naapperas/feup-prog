#include <iostream>

using namespace std;

/**
 * @brief Reads nElems elements from the console and stores them in the array.
 * 
 * @param a the array to store numbers in
 * @param nElems the number of elements to store
 */
void readArray(int a[], size_t nElems) {
    for (size_t i = 0; i < nElems; i++)
        cin >> a[i];
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
int findValueInArray(const  int  a[], size_t nElems, int value, size_t pos1, size_t pos2) {

    for (int i = pos1; i < pos2 && (i - pos1) < nElems; i++) {
        if (a[i] == value)
            return i; 
    }

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
int findMultValueInArray(const  int  a[], size_t nElems, int value, size_t pos1, size_t pos2, size_t index[]) {

    int j = 0;

    int idx = findValueInArray(a, nElems, value, pos1, pos2);

    if (idx != -1) {
        index[j++] = idx;

        while (idx != -1) {
            idx = findValueInArray(a, nElems, value, idx + 1, pos2);

            if (idx == -1) break;

            index[j++] = idx;
            
        }
    }

    return j;
}

int main(){

    int nElems;

    cout << "What is the number of elements you want to read? ";
    cin >> nElems;

    int a[nElems];
    size_t index[nElems]; // index has AT MOST nElems elements, so we can initialize this way
    readArray(a, nElems);

    int value;
    
    cout << "Input a number from the array: ";
    cin >> value;

    int numOccur = findMultValueInArray(a, nElems, value, 0, nElems, index);

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