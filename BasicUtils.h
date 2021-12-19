#include <iostream>
#include <string>

using namespace std;

//A general DFS function You can Swap out Anything in it according to your needs;
//a frequency Vector needs to be passed to the Function in order to mark the visited nodes. and prevent cyclic behaviour
//Also this function Uses vectors so #include <vector> is mandatory
void dfs (vector <vector<int>>& v1, vector <bool>& visitedFreqVec, int node) {
    //mark The Current Node as Visited
    visitedFreqVec[node] = true;
    //Loop Over All Children of the current node
    for (int i=0; i < v1[node].size(); i++) {
        int child = v1[node][i];
        //if The current child hasn't been visited yet, Then do a DFS starting from This child
        if (!visitedFreqVec[child]) {
            dfs(v1, visitedFreqVec, child);
        }
    }
}

string input(string prompt)
{
    string txt;
    cout << prompt;
    getline(cin, txt);
    return txt;
}

void print(string txt) {
    cout << txt << endl;
}

bool isPrime(int prNum) {
    if (prNum == 1) {
        return false;
    } else {
        for (int i=2; i<prNum; i++) {
            if (prNum % i == 0) {
                return false;
            }
        }
        return true;
    }
}

bool isPrimeSqrt(int prNum) {
    if (prNum == 1) {
        return false;
    } else {
        for (int i=2; i*i<=prNum; i++) {
            if (prNum % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int binSearch(int arra[], int arrS, int target) {
    int s = 0, e = arrS-1, mid = (s+e)/2;
    if (arra[0] > arra[1]) {
        cout << "Error: binSearch() function: Only accepts sorted arrays. It seams As If Your. Array Was Not Sorted. First Element was Greater Than The Second. Program Terminated." << endl;
        return 0;
    }

    while (s<e) {

        mid = (s+e)/2;
        if (arra[mid] >= target) {
            e = mid;
        }

        if (arra[mid] < target) {
            s = mid+1;
        }

        if (arra[mid] == target) {
            return mid;
        }
    }

    if (arra[e] != target) {
		cout << "binSearch() function: Target NotFound In Array. Execution Resumed." << endl;
	}
    return e;
}

int ston(string s) {
    int res = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] >='0' && s[i] <='9') {
            res*=10;
            res+= (int) s[i] - '0';
        }
    }
    return res;
}

