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
    
    string s,t;

    cin>>s>>t;

    int m=s.length(),n=t.length();

    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string result;

    int i=m,j=n;
    while(i>0 and j>0)
    {  
        if(s[i-1]==t[j-1]) 
        {
            result=s[i-1]+result;
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    cout<<result<<endl;
    
}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}