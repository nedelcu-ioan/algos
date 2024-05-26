/*
  (づ ￣ ³￣)づ
*/
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using ll = long long;
using ull = unsigned long long;
using lld = long double;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).begin(),(x).end()
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";  
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


signed main(int argc, char **argv, char **envp) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    map<char, int> f;
    for (char c : s) {
        f[c] += 1;
    }
    /// if some freq is odd put it in the middle
    /// more than 2 odd freq =? no solution
    int odd_cnt = 0;
    char odd_f_char;
    string ans = "";
    for (auto [c, cnt] : f) {
        if (cnt % 2 == 1) {
            odd_cnt += 1;
            odd_f_char = c;
        } else {
            for (int i = 0 ; i < cnt / 2 ; ++i) {
                ans += c;
            }
        }
    }
    if (odd_cnt > 1) {
        cout << "NO SOLUTION" << endl;
        return 0x0;
    }
    if (odd_cnt == 1) {
        for (int i = 0 ; i < f[odd_f_char] / 2 ; ++i) {
            ans += odd_f_char;
        }
        string rev = ans;
        std::reverse(rev.begin(), rev.end());
        ans += odd_f_char;
        ans = ans + rev;
    } else {
        string rev = ans;
        std::reverse(rev.begin(), rev.end());
        ans += rev;
    }

    cout << ans << endl;

    return 0x0;
}
