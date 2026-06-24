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
    ll n,k;
    cin >> n >> k;

    vll a(n);
    for (ll &x : a) cin >> x;

    vector<vector<ll>> dp(n+1,vll(k+1,0));

    dp[0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        vll prefix_sum(k+2,0);
        for(ll j=0;j<=k;j++)
        {
            prefix_sum[j+1]=(prefix_sum[j]+dp[i-1][j])%MOD;
        }
        for(ll j=0;j<=k;j++)
        {
            dp[i][j]=(prefix_sum[j+1]-prefix_sum[max(0LL,j-a[i-1])]+MOD)%MOD;
        }
    }

    cout<<dp[n][k]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}