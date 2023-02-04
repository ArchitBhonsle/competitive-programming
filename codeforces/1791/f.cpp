// Template {{{

#include <bits/stdc++.h>

using namespace std;

// Type abbreviations {{{

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvld = vector<vld>;
using vpi = vector<pi>;
using vpll = vector<pll>;
using vpd = vector<pld>;
using vb = vector<bool>;

// }}}

// Easy debugging (https://codeforces.com/blog/entry/68809) {{{

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(vector<bool> v) {
  bool first = true;
  cerr << "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      cerr << ", ";
    }
    first = false;
    __print(v[i]);
  }
  cerr << "}";
}
template <size_t N> void __print(bitset<N> bs) {
  string res = "<";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + bs[i]);
  }
  res += '>';
  cerr << res;
}
template <typename T> void __print(const T &x) {
  int j = 0;
  cerr << "{";
  for (auto &i : x)
    cerr << (j++ ? ", " : ""), __print(i);
  cerr << "}";
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << "(";
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << ")";
}
template <typename A, typename B, typename C>
void __print(const tuple<A, B, C> t) {
  cerr << "(";
  __print(get<0>(t));
  cerr << ", ";
  __print(get<1>(t));
  cerr << ", ";
  __print(get<2>(t));
  cerr << ")";
}
template <typename A, typename B, typename C, typename D>
void __print(const tuple<A, B, C, D> t) {
  cerr << "(";
  __print(get<0>(t));
  cerr << ", ";
  __print(get<1>(t));
  cerr << ", ";
  __print(get<2>(t));
  cerr << ", ";
  __print(get<3>(t));
  cerr << ")";
}
void _print() { cerr << " ]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifndef ONLINE_JUDGE
#define deb(...)                                                               \
  cerr << "~ [ " << #__VA_ARGS__ << " ] => [ ";                                \
  _print(__VA_ARGS__)
#define debn(...)                                                              \
  cerr << "~ [ ";                                                              \
  _print(__VA_ARGS__)
#else
#define deb(...)
#define debn(...)
#endif

// }}}

// }}}

const int MOD = 1e9 + 7;
const ll LLMOD = 1e18 + 7;

void init() {}

class BIT {
private:
  vector<int> bit;

public:
  BIT(size_t size) : bit(size + 1) {}
  auto update(size_t l, size_t r, int val = 1) {
    bit[l] += val, bit[r + 1] -= val;
  }
  auto get(size_t i) {
    int res = 0;
    for (int j = 0; j <= i; j++)
      res += bit[j];

    return res;
  }
};

void solve(int testcase) {
  size_t n, q;
  cin >> n >> q;
  // deb(n, q);
  vector<int> a(n);
  for (auto &ai : a)
    cin >> ai;
  // deb(a);

  BIT bit(n);

  while (q--) {
    string query;
    cin >> query;

    if (query == "1") {
      size_t l, r;
      cin >> l >> r;
      --l, --r;
      // deb(l, r);
      bit.update(l, r);
    } else {
      size_t x;
      cin >> x;
      --x;
      auto nUpdates = bit.get(x);
      // deb(x, a[x], nUpdates);

      auto num = a[x], temp = 0;
      while (nUpdates--) {
        while (num > 0)
          temp += num % 10, num /= 10;

        num = temp, temp = 0;
      }
      cout << num << endl;
      a[x] = num;
      bit.update(x, x, -bit.get(x));
    }
  }
}

// Main {{{

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(20);

  init();

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    solve(t);
}

// }}}

// vim: foldmarker={{{,}}} foldlevel=0 foldmethod=marker
