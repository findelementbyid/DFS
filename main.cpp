#include <iostream>
#include <vector>

using namespace std;

int maxs = INT_MAX;
vector<vector<int>> tmpArr;
void permutations(vector<vector<int>> jobs, int i, int n);
void cmax(vector<vector<int>> jobs, vector<int> object_value);

int main() {
    vector<vector<int>> jobs = {{0, 6},
                                {2, 2},
                                {2, 3},
                                {6, 2},
                                {7, 5},
                                {9, 2}};

    // print initial vector
    cout << "initial sequence: ";
    for (int i = 0; i < jobs.size(); i++) {
        cout << "[";
        for (int j = 0; j < 2; j++) {
            if (j < 1) cout << jobs[i][j] << ",";
            else cout << jobs[i][j];
        }
        if (i < jobs.size() - 1) cout << "], ";
        else cout << "]";
    }
    cout << endl;

    cout << "permutations: " << endl;
    permutations(jobs, 0, 6);

    //print the optimal(min.) object value
    cout << "min cmax is: " << maxs;
    
    return 0;
}

// calculate object value
int cmax(vector<vector<int>> tmp, int n) {
    int objectValue = 0;

    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i][0] <= objectValue) {
            objectValue += tmp[i][1];
        } else {
            int temp = tmp[i][0] - objectValue;
            objectValue += temp + tmp[i][1];
        }
    }

    cout << " = " << objectValue;

    return objectValue;
}


// find all permutation
void permutations(vector<vector<int>> jobs, int i, int n) {

    // base condition
    if (i == n - 1) {
        for (int j = 0; j < jobs.size(); j++) {
            cout << "[";
            for (int k = 0; k < 2; k++) {
                if (k < 1) cout << jobs[j][k] << ",";
                else cout << jobs[j][k];
            }
            if (j < jobs.size() - 1) cout << "],";
            else cout << "]";
            tmpArr.push_back(jobs[j]);
        }
        int objectValue = cmax(tmpArr, 6);
        cout << endl;
        tmpArr.clear();
        if (objectValue <= maxs) maxs = objectValue;
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