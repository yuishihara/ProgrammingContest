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

int main(){
    long long n = 0;
    long long k = 0;
    cin >> n >> k;
    if((n % 2) == 0) {
        if(k <= n / 2) {
            cout << 2 * k - 1 << endl;
        } else {
            cout << 2 * (k - n / 2) << endl;
        }
    } else {
        if(k <= (n / 2 + 1)) {
            cout << 2 * k - 1 << endl;
        } else {
            cout << 2 * (k - n / 2 - 1) << endl;
        }
    }
    return 0;
}
