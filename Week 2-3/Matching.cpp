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

    vector<vi> a(n,vi(n,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    unsigned int var=1<<n;
    vector<vll> dp(n+1,vll(var,0));

    dp[0][0]=1;

    for(int i=0;i<n;i++)
    {
        for(ll m=0;m<var;m++)
        {
            if(i==__builtin_popcountll(m))
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j] && !(m & 1<<j))
                    {
                        dp[i+1][m|1<<j]+=dp[i][m];
                        dp[i+1][m|1<<j]%=MOD;
                    }
                }
            }
        }
    }

    cout<<dp[n][var-1]<<endl;
}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}