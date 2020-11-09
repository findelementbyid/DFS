#include <iostream>
#include <vector>

using namespace std;
int count = 0;

void permutations(vector<vector<int>> jobs, int i, int n);
void cmax();


int main() {
    vector<vector<int>> jobs = {{0, 6},
                                {2, 2},
                                {2, 3},
                                {6, 2},
                                {7, 5},
                                {9, 2}};

    // print initial vector
    for (int i = 0; i < jobs.size(); i++) {
        for (int j = 0; j < 2; j++) {
            cout << jobs[i][j];
        }
        cout << endl;
    }
    cout << "permutation" << endl;
    permutations(jobs, 0, 6);
    cout << "permutations: " << count;

    return 0;
}

// calculate object value
void cmax(vector<vector<int>> jobs, vector<int> object_value) {

}

// find all permutation
void permutations(vector<vector<int>> jobs, int i, int n) {
    // base condition
    if (i == n - 1) {
        for (int k = 0; k < jobs.size(); k++) {
            cout << "[";
            for (int j = 0; j < 2; j++) {
                cout << jobs[k][j] << ",";
            }
            cout << "],";
        }
        cout << endl;
        count++;
        return;
    }

    // process each character of the remaining string
    for (int j = i; j < n; j++) {
        // swap character at index i with current character
        swap(jobs[i], jobs[j]);        // STL swap() used

        // recur for string [i+1, n-1]
        permutations(jobs, i + 1, n);

        // backtrack (restore the string to its original state)
        swap(jobs[i], jobs[j]);
    }
}


//void swap(vector<int> a, vector<int> b) {
//    vector<int> tmp = a;
//    a = b;
//    b = tmp;
//}


