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
/*
    cout << limit << " " << v.size() << " " << (limit > v.size()) << endl;

    if (limit > v.size()) {
        cout << "AAAAAAAAAAAAAAAAAAAAAAA" << endl;
        throw "'limit' can't be bigger than the size of the vector.";
    }
*/
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

/**
 * @brief Performs a bubble-sort on this vector
 * 
 * @param v the vector to sort
 * @param order the order in which to ascend
 */
void bubbleSort(vector<int> &v, char order = 'a') {

    for (int j = 0; j < v.size() - 1; j++) {

        bool breakRun = true;

        for (int i = 0; i < v.size() - j - 1; i++) {

            int curr = v.at(i);
            int next = v.at(i + 1);

            if ((order == 'a') ? (curr > next) : (curr < next)) {
                v.at(i) = next;
                v.at(i + 1) = curr;
                breakRun = false;
            }
        }

        if (breakRun) break;
    }
}

/**
 * @brief Performs a union of the elements of the vectors v1 and v2 and stores the result in v3
 * 
 * @param v1 
 * @param v2 
 * @param v3 
 */
void vectorUnion(const vector<int> &v1, const vector<int> &v2, vector<int> &v3) {

    for (auto a : v1)
        v3.push_back(a);


    for (auto a : v2)
        v3.push_back(a);

    removeDuplicates(v3);
    bubbleSort(v3);

}

void vectorIntersection(const vector<int> &v1, const vector<int> &v2, vector<int> &v3) {

    for (auto a : v1)
        if(inVector(v2, a))
            v3.push_back(a);


    for (auto a : v2)
        if(inVector(v1, a))
            v3.push_back(a);

    removeDuplicates(v3);
    bubbleSort(v3);
}

int main(){

    vector<int> a = {1, 2, 3}, b = {3, 4, 5}, c;
    vector<int> d = {1, 2, 3}, e = {3, 4, 5}, f;

    vectorUnion(a, b, c);
    vectorIntersection(d, e, f);

    for (auto a : c)
        cout << a << " ";

    cout << endl;

    for (auto a : f)
        cout << a << " ";

    cout << endl;

    return 0;
}