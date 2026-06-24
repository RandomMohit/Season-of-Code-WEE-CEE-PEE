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
    ll n,w,max_val=0;
    cin >> n >> w;

    vector<pair<ll,ll>> objects(n);
    for(ll i=0;i<n;i++)
    {
        cin>>objects[i].first>>objects[i].second;
        max_val=max(max_val,objects[i].second);
    }

    ll var=max_val*n;

    vector<ll> dp(var+1,INF);
    dp[0]=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=var;j>=objects[i].second;j--)
        {
            dp[j]=min(dp[j],dp[j-objects[i].second]+objects[i].first);
        }
    }
    
    

    ll result=0;

    for(int i=0;i<=var;i++)
    {
        if(dp[i]<=w)
        {
            result=i;
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