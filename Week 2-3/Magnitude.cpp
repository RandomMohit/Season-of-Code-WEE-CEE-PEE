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

void solve() {
    int n;
    cin >> n;

    vll a(n);
    vll prefix_sums(n+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        prefix_sums[i+1]=prefix_sums[i]+a[i];
    }

    ll min_val=distance(prefix_sums.begin(),min_element(all(prefix_sums)));

    cout<<prefix_sums[n]-2*prefix_sums[min_val]<<endl;
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}