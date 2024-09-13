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
    
    int n, k;
    cin >> n >> k;

	int ans = 1;
	vector<int> nrs(n + 1), loc(n + 1);
	
	for (int i = 1 ; i <= n ; ++i) {
		cin >> nrs[i];
		loc[nrs[i]] = i;
    }
    
    debug() << imie(loc);
    debug() << imie(nrs);
    
    for (int i = 1; i < n ; ++i) {
		if (loc[i + 1] < loc[i]) {
			ans++;
		}
	}
	
	
	while (k--) {
		int a, b;
		cin >> a >> b; // the query
		set<pair<int, int>> s;
		
		if (nrs[a] > 1) {s.insert({nrs[a] - 1, nrs[a]});}
		if (nrs[a] < n) {s.insert({nrs[a], nrs[a] + 1});}
		if (nrs[b] > 1) {s.insert({nrs[b] - 1, nrs[b]});}
		if (nrs[b] < n) {s.insert({nrs[b], nrs[b] + 1});}
	
	
		for (pair<int, int> p: s) {
			if (loc[p.first] > loc[p.second]) {
				ans--;
			}
		}
		
		swap(nrs[a], nrs[b]);
		loc[nrs[a]] = a;
		loc[nrs[b]] = b;
		
		for (pair<int, int> p: s) {
			if (loc[p.first] > loc[p.second]) {
				ans++;
			}
		}
		
		
		cout << ans << endl;
		s.clear();
	}
	
 	return 0x0;
}
