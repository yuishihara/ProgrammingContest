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

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first1,
    BidirectionalIterator last1,
    BidirectionalIterator first2,
    BidirectionalIterator last2)
{
    if ((first1 == last1) || (first2 == last2)) return false;
    BidirectionalIterator m1 = last1;
    BidirectionalIterator m2 = last2; --m2;
    while (--m1 != first1 && !(*m1 < *m2));
    bool result = (m1 == first1) && !(*first1 < *m2);
    if (!result) {
        while (first2 != m2 && !(*m1 < *first2)) ++first2;
        first1 = m1;
        std::iter_swap(first1, first2);
        ++first1;
        ++first2;
    }
    if ((first1 != last1) && (first2 != last2)) {
        m1 = last1; m2 = first2;
        while ((m1 != first1) && (m2 != last2)) {
            std::iter_swap(--m1, m2);
            ++m2;
        }
        std::reverse(first1, m1);
        std::reverse(first1, last1);
        std::reverse(m2, last2);
        std::reverse(first2, last2);
    }
    return !result;
}

template < class BidirectionalIterator >
bool next_combination(BidirectionalIterator first,
    BidirectionalIterator middle,
    BidirectionalIterator last) {
    return next_combination(first, middle, middle, last);
}

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
    return (a / gcd(a, b)) * b;
}

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    string str;
    repeat(i,X) {
        str += 'a';
    }
    repeat(i,Y) {
        str += 'b';
    }
    repeat(i,Z) {
        str += 'c';
    }
    string best = str;
    string temp;
    string temptemp;
    string temp_small;
    map<string, string> result;
    do {
        // cout << str << endl;
        temp = str;
        temptemp = temp + temp;
        map<string, string>::iterator itr = result.find(str);
        if (itr != result.end()) {
            string second = itr->second;
            if (temptemp.find(second) != string::npos) {
                continue;
            }
        }

        temp_small = str;
        int size = str.size();
        repeat(i,size - 1) {
            temp = temp.substr(1,temp.size()) + temp[0];
            if (result.find(temp) != result.end()) {
                break;
            }
            // cout << temp << endl;;
            if (temp < temp_small) {
                temp_small = temp;
            }
        }
        if (result.find(temp) != result.end()) {
            continue;
        }
        // cout << str << endl;
        result[str] = str;
        if (best < temp_small) {
            best = temp_small;
        }
    } while(next_permutation(str.begin(), str.end()));
    cout << best << endl;
    return 0;
}
