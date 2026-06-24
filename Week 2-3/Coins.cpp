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

    vector<double> p(n);
    for (double &x : p) cin >> x;

    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[1][0]=(double)(1.0)-p[0];
    dp[1][1]=p[0];

    for(int i=1;i<=n;i++)
    {   
        if(i!=1) dp[i][0]=((double)1-p[i-1])*dp[i-1][0];
        for(int j=1;j<=n;j++)
        {
            if(i==1 and j==1) continue;
            dp[i][j]=(dp[i-1][j-1]-dp[i-1][j])*p[i-1]+dp[i-1][j];
        }
    }

    double result=0;

    for(int i=(n+1)/2;i<=n;i++)
    {
        result+=dp[n][i];
    }

    cout<<fixed<<setprecision(15)<<result<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}