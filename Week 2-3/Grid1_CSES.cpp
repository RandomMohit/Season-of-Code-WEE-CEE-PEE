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

    vector<vll> dp(n+1,vll(n+1,0));
    dp[1][1]=1;

    char c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> c;
            if(i==1 and j==1)
            {
                if(c=='*')
                {
                    cout<<0<<endl;
                    return;
                }
                else
                {
                    continue;
                }
            }
            if(c=='.')
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])% MOD;
            }
        }
    }

    cout<<dp[n][n]<<endl;


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}