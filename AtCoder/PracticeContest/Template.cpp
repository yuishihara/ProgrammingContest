#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

#define all(c) c.begin(),c.end()
#define repeat(i,n) for(int i=0;i<static_cast<int>(n);i++)
#define debug(x) #x << "=" << (x)
#define dump(x) cerr << debug(x) << " (L:" << __LINE__ << ")"<< endl

typedef long long ll;
typedef vector<int> vi;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec){
    os << "[";
    for(int i = 0; i < vec.size(); i++){
        os << vec[i] << ",";
    }
    os << "]";
    return os;
}

template<typename T>
T input(){
    T t;
    cin >> t;
    return t;
}

template<typename T>
vector<T> input(const int N){
    vector<T> v(N);
    repeat(i,N) cin >> v[i];
    return v;
}

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b){
    return (a * b) / gcd(a, b);
}

int query(char A, char B) {
    cout << "?" << " " << A << " " << B;
    fflush(stdout);

    char result;
    cin >> result;
    if (result == '<') {
        return 1;
    } else if (result == '>') {
        return -1;
    } else {
        return 0;
    }
}

int comparison['Z' + 5]['Z' + 5];
bool comparator(char i,char j) {
    if (comparison[i][j] == -1) {
        cout << "?" << " " << i << " " << j << endl;
        fflush(stdout);
        char result;
        cin >> result;
        if (result == '>') {
            comparison[i][j] = true;
            comparison[j][i] = false;
            return true;
        } else {
            comparison[i][j] = false;
            comparison[j][i] = true;
            return false;
        }
    } else {
        return comparison[i][j];
    }
}

int binarySearch(char a[], char item, int low, int high) {
    if (high <= low) {
        return (comparator(item, a[low])) ? (low + 1): low;
    }

    int mid = (low + high) / 2;

    if (item == a[mid]) {
        return mid + 1;
    }

    if (comparator(item, a[mid])) {
        return binarySearch(a, item, mid+1, high);
    }
    return binarySearch(a, item, low, mid-1);
}

void insertionSort(char a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inserted
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}

int main(){
    ll N, Q;
    cin >> N >> Q;
    char str[N + 1];
    memset(str, '\0', sizeof(str));
    memset(comparison, -1, sizeof(comparison));
    repeat(i,N) {
        str[i] = ('A' + i);
    }

    insertionSort(str, N);

    cout << "! " << str << endl;
    fflush(stdout);
    return 0;
}
