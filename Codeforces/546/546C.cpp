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

bool isSameOrder(vi stack1, vi stack2) {
    if (stack1.size() != stack2.size()) {
        return false;
    }
    for (int i = 0; i < stack1.size(); ++i) {
        if (stack1[i] != stack2[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int cardsTotal;
    cin >> cardsTotal;

    int n;
    cin >> n;
    vi deckA = input<int>(n);
    vector<vi> patternsA;
    patternsA.push_back(deckA);

    cin >> n;
    vi deckB = input<int>(n);
    vector<vi> patternsB;
    patternsB.push_back(deckB);

    int playerA;
    int playerB;
    int count = 0;
    while (1) {
        playerA = deckA.front();
        playerB = deckB.front();
        deckA.erase(deckA.begin());
        deckB.erase(deckB.begin());
        if (playerB < playerA) {
            deckA.push_back(playerB);
            deckA.push_back(playerA);
        } else {
            deckB.push_back(playerA);
            deckB.push_back(playerB);
        }
        count++;

        if (deckA.size() == 0) {
            cout << count << " " << 2 << endl;
            break;
        }
        if (deckB.size() == 0) {
            cout << count << " " << 1 << endl;
            break;
        }

        bool appeared = false;
        for (int i = 0; i < patternsA.size(); ++i) {
            if (isSameOrder(deckA, patternsA[i]) && isSameOrder(deckB, patternsB[i])) {
                cout << -1 << endl;
                appeared = true;
                break;
            }
        }
        if (appeared) {
            break;
        }
        patternsA.push_back(deckA);
        patternsB.push_back(deckB);
    }

    return 0;
}
