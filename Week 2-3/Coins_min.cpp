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
    ll n, x;
    cin >> n >> x;

    vll a(n);
    for (ll &x : a) cin >> x;
    sort(all(a));

    vll dp(x+1,-1);
    dp[0]=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=a[j] && dp[i-a[j]]!=-1)
            {
                if(dp[i]==-1)
                {
                    dp[i]=1+dp[i-a[j]];
                }
                else
                {
                    dp[i]=min(dp[i],1+dp[i-a[j]]);
                }
            }
        }
    }
    cout<<dp[x]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}