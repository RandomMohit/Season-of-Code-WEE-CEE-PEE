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

ll recurse(vll &v,int length ,int start, int end, vector<vll> &dp)
{   
    if(end==start) return dp[start][end]=((length%2==0)?-v[start]:v[start]);

    if(dp[start][end]!=INF) return dp[start][end];

    if(length%2==(start+end)%2)
    {
        return dp[start][end]=min(recurse(v,length,start+1,end,dp)-v[start],recurse(v,length,start,end-1,dp)-v[end]);
    }
    else
    {
        return dp[start][end]=max(recurse(v,length,start+1,end,dp)+v[start],recurse(v,length,start,end-1,dp)+v[end]);
    }
}

void solve() {
    int n;
    cin >> n;

    vll a(n);
    for (ll &x : a) cin >> x;

    //stores value of X-Y(maximisizing it and minimising it as per turn)
    vector<vector<ll>> dp(n,vll(n,INF));

    recurse(a,n,0,n-1,dp);

    cout<<dp[0][n-1]<<endl;


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}