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
    ll n,w;
    cin >> n >> w;

    vector<pair<ll,ll>> objects(n);
    for(ll i=0;i<n;i++)
    {
        cin>>objects[i].first>>objects[i].second;
    }

    vector<ll> dp(w+1,0);
    
    for(ll i=0;i<n;i++)
    {
        for(ll j=w;j>=objects[i].first;j--)
        {
            
            dp[j]=max(dp[j],dp[j-objects[i].first]+objects[i].second);
            
        }
    }

    cout<<dp[w]<<endl;


}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}