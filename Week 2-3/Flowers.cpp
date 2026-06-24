#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

const int MOD = 1e9 + 7;
const ll INF = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif

const int N = 2e5+1; 
int n;
ll t[2 * N];

void modify(int p, ll value) {  
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p],t[p^1]);
}

ll query(int l, int r) {  
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res,t[l++]);
    if (r&1) res = max(res,t[--r]);
  }
  return res;
}

void solve() {
    cin >> n;

    vector<pair<int,ll>> h(n);
    for (auto &x : h) cin >> x.first;
    for (auto &x : h) cin >> x.second;

    fill(t,t+2*N,0LL);

    for(int i=0;i<n;i++)
    {
        modify(h[i].first-1,h[i].second+query(0,h[i].first-1));
    }

    cout<<t[1]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}