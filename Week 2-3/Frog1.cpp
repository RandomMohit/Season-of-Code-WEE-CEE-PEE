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

    vll h(n,0);
    for (ll &x : h) cin >> x;

    vll dp(n,0);

    dp[n-1]=0;
    dp[n-2]=(h[n-1]>h[n-2]?(h[n-1]-h[n-2]):(h[n-2]-h[n-1]));

    for(int i=n-3;i>=0;i--)
    {
        dp[i]=min(dp[i+1]+(h[i+1]>h[i]?(h[i+1]-h[i]):(h[i]-h[i+1])),dp[i+2]+(h[i+2]>h[i]?(h[i+2]-h[i]):(h[i]-h[i+2])));
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