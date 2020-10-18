#include <iostream>
#include <string>

using namespace std;

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

