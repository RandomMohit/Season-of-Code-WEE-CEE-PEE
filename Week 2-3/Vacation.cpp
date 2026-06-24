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

    vll a(n),b(n),c(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }

    vector<vector<ll>> dp(n,vector<ll>(3,0));

    dp[n-1][0]=a[n-1];
    dp[n-1][1]=b[n-1];
    dp[n-1][2]=c[n-1];

    for(int i=n-2;i>=0;i--)
    {
        dp[i][0]=max(dp[i+1][1],dp[i+1][2])+a[i];
        dp[i][1]=max(dp[i+1][0],dp[i+1][2])+b[i];
        dp[i][2]=max(dp[i+1][1],dp[i+1][0])+c[i];
    }

    cout<<max(max(dp[0][0],dp[0][1]),dp[0][2])<<endl;


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}