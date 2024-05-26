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

void solve() {
    int l, r;
    cin >> l >> r;
    debug() << imie(l) << imie(r);

    /// t op 1 and q op 2
    /// 2t + q = l
    /// t + 2q = r
    ///------------ (+)
    /// 3(t + q) = l + r => l + r div 3
    /// t + q = 1/3(l + r)
    /// => t = l - 1/3(l + r)
    /// => q = r - 1/3(l + r)

    int s = l + r;
    if (s % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    int t = l - s / 3;
    int q = r - s / 3;

    if (t >= 0 && q >= 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(int argc, char **argv, char **envp) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0x0;
}
