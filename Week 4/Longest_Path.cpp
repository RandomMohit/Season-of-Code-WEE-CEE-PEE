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
int dfs(int value,vector<vi> &v,vector<int> &dp)
{
     if(dp[value]!=-1)
     {
        return dp[value];
     }
     
     int result=-1;
     for(auto x:v[value])
     {
        result=max(result,dfs(x,v,dp));
     }
     result++;
     return dp[value]=result;
}
void solve() {
    int n,m;
    cin >> n >> m;

    vector<vi> a(n+1);
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        a[u].pb(v);
    }

    vector<int> dp(n+1,-1);

    for(int i=1;i<=n;i++)
    {
        dfs(i,a,dp);
    }

    cout<<*max_element(all(dp))<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}