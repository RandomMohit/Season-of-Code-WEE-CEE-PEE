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

    int a=0,b=0,c=0;

    int var;
    for(int i=0;i<n;i++)
    {
        cin >> var;
        if(var==1) a++;
        if(var==2) b++;
        if(var==3) c++;
    }

    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(n+1,0)));

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(int k=0;k<=n;k++)
            {   
                if(k+j+i==0) continue;

                dp[k][j][i]=(k>0?dp[k-1][j][i]*k/(k+j+i):0)+((k<n && j>0)?dp[k+1][j-1][i]*j/(k+j+i):0)+((j<n && i>0)?dp[k][j+1][i-1]*i/(k+j+i):0)+((1.0*n)/(k+j+i));
            }
        }  
    }

    cout<<setprecision(15)<<dp[a][b][c]<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}