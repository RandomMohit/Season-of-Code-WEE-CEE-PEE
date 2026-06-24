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
    int n, x;
    cin >> n >> x;

    vector<pll> books(n);
    for (auto &y : books) cin >> y.first;
    for (auto &y : books) cin >> y.second;
    
    vll dp(x+1,0);
    
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=books[i].first;j--)
        {
            dp[j]=max(dp[j],dp[j-books[i].first]+books[i].second);
        }
    }

    cout<<dp[x]<<endl;


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}