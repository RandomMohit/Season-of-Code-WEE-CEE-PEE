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
    int n,m,k;
    cin>>n>>m>>k;

    string s;
    cin>>s;
    s="L"+s+"L";
    vll dp(n+2,INT_MAX);

    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]=='W')
        {
            if(s[i+1]=='W')
            {
                dp[i+1]=min(dp[i+1],dp[i]+1);
            }
            if(s[i+1]=='L')
            {
                dp[i+1]=min(dp[i+1],dp[i]);
            }
            if(s[i+1]=='C')
            {
                dp[i+1]=min(dp[i+1],(ll)INT_MAX);
            }
        }
        if(s[i]=='L')
        {   for(int j=1;j<=m;j++)
            {   if(i+j>n+1) break;
                if(s[i+j]=='W')
                {
                    dp[i+j]=min(dp[i+j],dp[i]+1);
                }
                if(s[i+j]=='L')
                {
                    dp[i+j]=min(dp[i+j],dp[i]);
                }
                if(s[i+j]=='C')
                {
                    dp[i+j]=min(dp[i+j],(ll)INT_MAX);
                }
            }
        }
    }

    if(dp[n+1]>k) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}