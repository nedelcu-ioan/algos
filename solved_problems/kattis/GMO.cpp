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

vector<vector<int>> memo(10001, vector<int>(5001, -1));

int find_cost(map<char, int> &c, string &s, string &t, int pos_s, int pos_t) {

    if (memo[pos_s][pos_t] != -1) {
        return memo[pos_s][pos_t];
    }
    const int n = (int)s.size();
    const int m = (int)t.size();

    if (pos_t == m) {
        return 0; // done matching target string
    }

    int ans = (int)1e9 + 7; // minimum cost for current state

    // use current character if is good
    if (pos_s < n && s[pos_s] == t[pos_t]) {
        ans = min(ans, find_cost(c, s, t, pos_s + 1, pos_t + 1));
    }

    // don't use current character
    if (pos_s < n) {
        ans = min(ans, find_cost(c, s, t, pos_s + 1, 0));
    }

    // buy current character
    ans = min(ans, c[t[pos_t]] + find_cost(c, s, t, pos_s, pos_t + 1));

    return memo[pos_s][pos_t] = ans;
}


int find_cost_dp(map<char, int> &c, string &s, string &t) {
    int n = (int)s.size();
    int m = (int)t.size();
    const int INF = (int)1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    for (int i = 0; i <= n; ++i) {
        dp[i][m] = 0;
    }

    debug() << imie(n) << imie(m);

    for (int i = n; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i < n && s[i] == t[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
            }
//            if (i < n) {
//                dp[i][j] = min(dp[i][j], dp[i + 1][0]);
//            }
//            dp[i][j] = min(dp[i][j], c[t[j]] + dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

signed main(int argc, char **argv, char **envp) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    vector<int> cost(300, 0);
    string letters = "ACGT";
    for (int i = 0, c; i < 4; ++i) {
        cin >> c;
        cost[letters[i]] = c;
    }

    // debug() << imie(s) << imie(t) << imie(cost);
    // n = O(1e4) , m = O(5e3)
    // dp[n][m] = minima cost to match first m characters from t using n characters from s
    // dp[n][m] = {
    //      skip current character
    //      use it (if equal to the target[pos])
    //      buy it
    //}
    // dp[i][j] -> update with minima dp[i + 1][j] //skip current character
    // dp[i][j] -> use current character -> update dp[i + 1][j + 1] // if (s[i] == t[j])
    // dp[i][j] -> buy the current character -> update dp[i][j + 1] = dp[i][j] + cost[t[j]]
    // solution on dp[n][m]

    // cout << find_cost(cost, s, t, 0, 0) << endl;

    const int n = (int)s.size();
    const int m = (int)t.size();
    const int INF = (int)1e9 + 7;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

    for (int i = 0; i <= n; ++i) {
        dp[i][m] = 0;
    }

    debug() << imie(n) << imie(m);

    for (int i = n; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (i < n && s[i] == t[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
            }
            if (i < n) {
                dp[i][j] = min(dp[i][j], dp[i + 1][0]);
            }
            dp[i][j] = min(dp[i][j], cost[t[j]] + dp[i][j + 1]);
        }
    }

    cout << dp[0][0] << endl;
    return 0x0;
}
