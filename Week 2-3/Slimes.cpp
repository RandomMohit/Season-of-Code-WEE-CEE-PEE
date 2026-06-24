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

ll recurse(int start,int end,vector<vll> &dp,vll &prefix_sums)
{
    if(start==end) return dp[start][end]=0LL;
    if(dp[start][end]!=INF) return dp[start][end];
    for(int i=start;i<end;i++)
    {
        dp[start][end]=min(dp[start][end],recurse(start,i,dp,prefix_sums)+recurse(i+1,end,dp,prefix_sums)+prefix_sums[end]-prefix_sums[start-1]);
    }
    return dp[start][end];
}

void solve() {
    int n;
    cin >> n;

    vll a(n);
    for (ll &x : a) cin >> x;

    vector<vll> dp(n+1,vll(n+1,INF));

    vll prefix_sums(n+1,0);

    for(int i=1;i<=n;i++)
    {
        prefix_sums[i]=(prefix_sums[i-1]+a[i-1]);
    }

    recurse(1,n,dp,prefix_sums);

    cout<<dp[1][n]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}