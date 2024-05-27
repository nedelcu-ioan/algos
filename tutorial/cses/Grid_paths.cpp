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

int cnt = 0;
string steps;
bool v[9][9];

unordered_map<char, pair<int, int>> d = {
        {'U', {-1, 0}},
        {'R', {0, 1}},
        {'D', {1, 0}},
        {'L', {0, -1}}
};


void bktr(int index = 0, int x = 1, int y = 1) {
    if ((v[x - 1][y] && v[x + 1][y]) && (!v[x][y - 1] && !v[x][y + 1])) {
        return;
    }

    if ((!v[x - 1][y] && !v[x + 1][y]) && (v[x][y - 1] && v[x][y + 1])) {
        return;
    }

    if (x == 7 && y == 1) {
        if (index == 48) ++cnt;
        return;
    }

    if (index == 48) return;


    v[x][y] = true;

    if (steps[index] == '?') {
        for (auto dir : d) {
            int dx = dir.second.first;
            int dy = dir.second.second;

            if (!v[x + dx][y + dy]) {
                bktr(index + 1, x + dx, y + dy);
            }
        }
    } else {
        int dx = d[steps[index]].first;
        int dy = d[steps[index]].second;

        if (!v[x + dx][y + dy]) {
            bktr(index + 1, x + dx, y + dy);
        }

    }

    v[x][y] = false;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0 ; i <= 8 ; ++i) {
        v[i][0] = true;
        v[0][i] = true;
        v[i][8] = true;
        v[8][i] = true;
    }

    cin >> steps;
    bktr();
    cout << cnt << endl;

    return 0x0;
}
