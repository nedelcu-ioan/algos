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
    debug() << imie("-- merge --");
    int n, x; cin >> n >> x; debug() << imie(n) << imie(x);
    vector<int> p(n); for(int & it: p) cin >> it;
    debug() << imie(p);
    
    sort(p.begin(), p.end()); debug() << imie(p);
    // Incerci sa pui cate 2 in barca (cel mai mare si cel mai mic)
    // daca suma este mai mare de x atunci este necesara o barca extra
    
    int ans = n;

    // try to echo boats 
    int left = 0, right = n - 1; 

    while (left < right) {
        if (p[left] + p[right] <= x) {
            ans--;
            left++, right--;
        } else {
            right--;
        }
    }
    
    cout << ans << endl;

    return 0x0;
}
