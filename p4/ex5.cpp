#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Checks if the value is present int the given vector.
 * 
 * @param v the vector to search in
 * @param value the value to search for
 * @param limit the upper bound to search for elements, or -1 if to search for all the elements
 * @return true if the value is present in the vector
 * @return false if the value is not present in the vector
 */
bool inVector(const vector<int> &v, int value, int limit = -1) {

    if (limit > v.size())
        throw "'limit' can't be bigger than the size of the vector.";

    int actualLimit = (limit == -1) ? v.size() : limit; // parsing default arg

    for (int i = 0; i < actualLimit; i++)
        if (v.at(i) == value)
            return true;

    return false;
}

/**
 * @brief Removes from the vector the element at the given index
 * 
 * @param v the vector to remove the element from
 * @param index the index of the element to remove
 */
void removeFromVector(vector<int> &v, int index) {

    if (index < 0 || index >= v.size())
        throw "Index out of bounds";

    for(int j = index + 1; j < v.size(); j++)
        v.at(j - 1) = v.at(j); //shift all elements right of the index to the left

    v.resize(v.size() - 1); // since the last element is duplicated, shrink the vector by one

}

/**
 * @brief Removes duplicates from the vector.
 * 
 * @param v the vector to remove duplicates from
 */
void removeDuplicates(vector<int>& v) {

    for (int i = 1; i < v.size(); i++)
        if (inVector(v, v.at(i), i)) // check vector until the current index, if true, then we are a duplicate value
            removeFromVector(v, i--); // removes from vector and decreases i

}

int main(){

    vector<int> a = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 23, 4, 4, 4, 5, 5, 6, 7, 7, 7, 8, 8};

    removeFromVector(a, 11); //checking if it works

    removeDuplicates(a);

    for (int i : a) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}