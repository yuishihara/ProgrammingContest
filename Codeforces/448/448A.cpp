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

bool isPrime(const long number) {
    static vector<int> primeNumbers;
    if(primeNumbers.size() == 0) {
        primeNumbers.push_back(2);
    }
    for(int i = 0; i < primeNumbers.size(); ++i) {
        if(number == primeNumbers[i]) {
            return true;
        }
        if(number % primeNumbers[i] == 0) {
            return false;
        }
    }
    primeNumbers.push_back(number);
    return true;
}

int main(){
    vector<int> cups = input<int>(3);
    vector<int> medals = input<int>(3);
    int shelves = input<int>();

    int cupsTotal = cups[0] + cups[1] + cups[2];
    int medalsTotal = medals[0] + medals[1] + medals[2];

    int needShelf = 0;
    if((cupsTotal % 5) != 0) {
        needShelf += 1;
    }
    needShelf += cupsTotal / 5;

    if((medalsTotal % 10) != 0) {
        needShelf += 1;
    }
    needShelf += medalsTotal / 10;

    cout << ((needShelf <= shelves) ? "YES" : "NO") << endl;

    return 0;
}
