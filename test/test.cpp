#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef LOCAL // =========== Local ===========
void dbg() { cerr << '\n'; }
template <class T, class... U> void dbg(T a, U... b) {
  cerr << a << ' ', dbg(b...);
}
template <class T> void org(T l, T r) {
  while (l != r)
    cerr << *l++ << ' ';
  cerr << '\n';
}
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))
#else // ======== OnlineJudge ========
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define X first
#define Y second
#define rep(i, a) for (ll i = 0; i < a; i++)
#define IO                                                                     \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0)

template <class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
const int mod = 1e9 + 7, N = 1 << 20, INF = 0x3f3f3f3f;

struct trie {
  trie *child[26];
  int cnt;
  string *s;
  trie() {
    cnt = 0;
    for (int i = 0; i < 26; i++)
      child[i] = nullptr;
  }
};

pair<int, string *> dfs(trie *cur) {
  pair<int, string *> res = {cur->cnt, cur->s};
  for (int i = 0; i < 26; i++) {
    if (cur->child[i]) {
      auto p = dfs(cur->child[i]);
      if (p.first > res.first)
        res = p;
    }
  }
  cur->cnt = res.first;
  cur->s = res.second;
  return res;
}

void solve() {
  int n;
  cin >> n;
  trie *root = new trie();
  for (int i = 0; i < n; i++) {
    string *s = new string();
    cin >> *s;
    trie *cur = root;
    for (char c : *s) {
      int id = c - 'a';
      if (!cur->child[id])
        cur->child[id] = new trie();
      cur = cur->child[id];
    }
    cur->s = s;
    cur->cnt++;
  }
  dfs(root);
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    trie *cur = root;
    for (char c : s) {
      int id = c - 'a';
      if (!cur->child[id]) {
        cout << "-1\n";
        goto end;
      }
      cur = cur->child[id];
    }
    cout << *cur->s << ' ' << cur->cnt << '\n';
  end:;
  }
}

signed main() {
  IO;
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}