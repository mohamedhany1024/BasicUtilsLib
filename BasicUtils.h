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

// quick_power: expects base and exponent. quickly computes values of a number raised to a big power!

long long quick_power(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			res*=a;
		}

		a*=a;
		b/=2;
	}
	return res;
}
// quick_power_mod: accepts base, exponent and mod. quicly computes valuse of a number raised to a HUGE power, it accespts a mod paramter for comically large values
long long quick_power_mod(long long a, long long b, long long mod) {
	long long res = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			res = ((res % mod)*(a % mod) % mod);
		}

		a = ((a%mod)*(a%mod) % mod);
		b/=2;
	}
	return res;
}

// fact_compute: expects a vector and an integer n, make sure your vector is big enough for the
// number of digits of the factorial.
// usage: computes HUGE factroials. The result is a vector with the
// factorial represented digit by digit inside of the vector. The result is
// represented in reverse, you will have to iterate over the vector form the bottom to the top
// to see it correctly
// returns: m the the no. of digits
// of the resultant factorial

int fact_compute (vector <int> &vect, int n) {
	int m = 1;
	int carry = 0;
	int temp = 0;

	vect[0] = 1;

	for (int i=2; i<=n; i++) {

		for (int j=0; j<m; j++) {
			temp = i*vect[j];
			if ((temp % 10)+carry <= 9) {
				vect[j] = (temp % 10)+carry;
				temp /= 10;
				carry = temp;
			} else {
				carry+=temp;
				vect[j] = carry % 10;
				carry /= 10;
			}
		}

		while (carry > 0) {
			m++;
			vect[m-1] = carry%10;
			carry/=10;
		}
	}
	return m;
}

//compute_fact_div: expects a vector, an integer n, and an integer str
//usage: divides two factorials by each other the result is stored in the passed vector.
//The result is
// represented in reverse, you will have to iterate over the vector form the bottom to the top
// to see it correctly
//The factorial is represented digit by digit in the vector
//returns: m the number of digits of the resultant factorial

int compute_fact_div(vector <int> &vect, int n, int str) {
    int temp, carry, m;
    if (n < str) {
    	swap(n, str);
    }
    vect[0] = str+1;
    m = 1;
    temp = 0;
    carry = 0;
    for (int i=str+2; i<=n; i++) {

        for (int j=0; j<m; j++) {
            temp = i*vect[j];
            if ((temp%10)+carry <= 9) {
                vect[j] = (temp % 10) + carry;
                temp /= 10;
                carry = temp;
            } else {
                carry+=temp;
                vect[j] = carry % 10;
                carry/=10;
            }

        }

        while (carry > 0) {
            m++;
            vect[m-1] = carry % 10;
            carry /= 10;
        }
    }
    return m;
}

//compute_fact_multip: expects a vector, an integer n, and an integer c
//usage: multiplies n! by c!. The resultant factorial is represented digit by digit The result is
// represented in reverse, you will have to iterate over the vector form the bottom to the top
// to see it correctly
//inside of the vector
//returns: m the number of digits of the resultant factorial


int compute_fact_multip(vector <int> &vect, int n, int c) {
    int temp, carry, m;
    vect[0] = 1;
    m = 1;
    temp = 0;
    carry = 0;
    for (int i=2; i<=n; i++) {

        for (int j=0; j<m; j++) {
            if (i <= c) {
                temp = (i*i)*vect[j];
            } else {
                temp = i*vect[j];
            }
            if ((temp%10)+carry <= 9) {
                vect[j] = (temp % 10) + carry;
                temp /= 10;
                carry = temp;
            } else {
                carry+=temp;
                vect[j] = carry % 10;
                carry/=10;
            }

        }

        while (carry > 0) {
            m++;
            vect[m-1] = carry % 10;
            carry /= 10;
        }
    }
    return m;
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

