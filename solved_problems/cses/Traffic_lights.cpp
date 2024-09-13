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
    
    /// 8 -> 3
    /// 0 1 2 3 4 5 6 7 8 
    ///       * 
    ///             *
    /// intervals
    /// left, right
    /// left
    
    int n, k;
	cin >> n >> k;
	
	vector<int> a(k);
	for (int & i : a) {
		cin >> i;
	}
	
	debug() << imie(a);
	
	set<int> l{0, n};
	multiset<int> dist{n};
	
	debug() << imie(l) << imie(dist);
	
	for (int c : a) {
		auto it1 = l.upper_bound(c);
		auto it2 = it1;
		--it2;
		
		
		cout << "| " << *it1 << " " << *it2 << endl;
		
		dist.erase(dist.find(*it1 - *it2));
		dist.insert(c - *it2);
		dist.insert(*it1 - c);
		
		l.insert(c);
		
		auto ans = dist.end();
		--ans;
		cout << *ans << " ";
	}
    
    return 0x0;
}
