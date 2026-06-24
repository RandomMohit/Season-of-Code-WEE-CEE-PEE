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
ll recurse(int node,vector<unordered_set<int>> &tree,vector<vll> &dp,int colour)
{
    if(dp[node][colour]) return dp[node][colour];
    
    dp[node][colour]=1;
    for(auto &x: tree[node])
    {
        tree[x].erase(node);
        if(colour==0)
        {
            dp[node][colour]=dp[node][colour]*((recurse(x,tree,dp,0)+recurse(x,tree,dp,1))%MOD);
            dp[node][colour]%=MOD;
        }
        else
        {
            dp[node][colour]*=recurse(x,tree,dp,0)%MOD;
            dp[node][colour]%=MOD;
        }
        tree[x].insert(node);
    }

    return dp[node][colour];
}
void solve() {
    int n;
    cin >> n;

    vector<unordered_set<int>> tree(n+1);

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;

        tree[u].insert(v);
        tree[v].insert(u);
    }

    vector<vll> dp(n+1,vll(2,0));

    recurse(1,tree,dp,0);
    recurse(1,tree,dp,1);

    cout<<(dp[1][0]+dp[1][1])%MOD<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}