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

    vll dp(7,0);
    dp[0]=1;
    dp[1]=dp[0];
    dp[2]=2*dp[1];
    dp[3]=2*dp[2];
    dp[4]=2*dp[3];
    dp[5]=2*dp[4];
    dp[6]=2*dp[5];

    if(n<7) {cout<<dp[n]<<endl; return;}
    for(int i=7;i<=n;i++)
    {
        dp[0]=dp[1];
        dp[1]=dp[2];
        dp[2]=dp[3];
        dp[3]=dp[4];
        dp[4]=dp[5];
        dp[5]=dp[6];
        dp[6]=(dp[5]+dp[4]+dp[3]+dp[2]+dp[1]+dp[0])%MOD;
    }
    cout<<dp[6]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}