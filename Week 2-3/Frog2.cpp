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
    int n,k;
    cin >> n >> k;

    vll h(n,0);
    for (ll &x : h) cin >> x;

    vll dp(n,0);

    for(int i=n-2;i>=0;i--)
    {   
        dp[i]=dp[i+1]+llabs(h[i+1]-h[i]);
        int j=2;
        while(j<=k)
        {
            if (i+j<n)
            {
                dp[i]=min(dp[i+j]+llabs(h[i+j]-h[i]),dp[i]);
            }
            else break;
            j++;
        }

    }

    cout<<dp[0]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}