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

    vi digits(7,0);
    vll dp(n+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=n;i++)
    {   
        int temp=i;
        for(int j=0;j<7;j++)
        {
            digits[j]=temp%10;
            temp/=10;
            dp[i]=min(1+dp[i-digits[j]],dp[i]);
        }
    }
    cout<<dp[n]<<endl;
}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}