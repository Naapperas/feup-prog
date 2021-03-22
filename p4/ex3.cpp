#include <iostream>
#include <vector>

using namespace std;

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

void bubbleSort(vector<int> &v, bool f(int, int) = [](int a, int b) {return a > b;}) {

    for (int j = 0; j < v.size() - 1; j++) {

        bool breakRun = true;

        for (int i = 0; i < v.size() - j - 1; i++) {

            int curr = v.at(i);
            int next = v.at(i + 1);

            if (f(curr, next)) {
                v.at(i) = next;
                v.at(i + 1) = curr;
                breakRun = false;
            }
        }

        if (breakRun) break;
    }

}

int main(){

    vector<int> a = {1,2,4,3, 3, 4, 5, 7, 3,1, 2, 5,6, 7, 4, 3, 3, 6, 8,9, 9,7,45,2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    bubbleSort(a, 'a');

    for (int i : a) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}