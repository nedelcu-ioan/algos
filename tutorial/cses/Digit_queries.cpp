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

ll pow10(int exp) {
    ll product = 1;
    for (int i = 0; i < exp; i++) { product *= 10; }
    return product;
}

char solve(ll n) {
    /// 1 ... 9 -                   >    9 numbers * 1
    /// 10 ... 99   -> 99 - 10 + 1 ->   90 numbers * 2
    /// 100 ... 999 -> 999 - 100 +1 -> 900 numbers * 3
    /// 1000 ... 9999 -> 9999 - 1000 + 1 -> 9000 numbers * 4

    ll digits = 1;
    while (n > digits * 9 * pow10(digits - 1)) {
        n -= digits * 9 * pow10(digits - 1);
        ++digits;
    }

    ll number = (n - 1) / digits + pow10(digits - 1);
    ll number_pos = (n - 1) % digits;
    return to_string(number)[number_pos];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q; cin >> q;
    while(q--) {
        ll n; cin >> n;
        cout << solve(n) << endl;
    }
    return 0x0;
}
