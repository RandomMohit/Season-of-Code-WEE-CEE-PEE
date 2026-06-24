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

ll decomp(ll n, ll k)
{   
    if(n==1) return 0;
    vll divisor;

    for(ll i=1;i*i<=n;i++)
    {
        if(n%i == 0) 
        {
            divisor.pb(i);
            if(i*i!=n) divisor.pb(n/i);
        } 
    }

    ll length=divisor.size();
    vll dp(length,INT_MAX);
    dp[0]=0;
    sort(all(divisor));
    for(ll i=1;i<length;i++)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(divisor[i]/divisor[j]>k) break;
            if(divisor[i]%divisor[j]==0)
            {
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
    }
    if(dp[length-1]==INT_MAX) return -1;
    
    return dp[length-1];
}


void solve() {
    ll x,y,k;
    cin >> x>> y >> k;

    ll a,b;
    ll g=__gcd(x,y);
    x=x/g;
    y=y/g;
    a=decomp(x,k);
    b=decomp(y,k);

    if(a==-1 or b==-1) cout<<-1<<endl;
    else cout<<a+b<<endl;
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}