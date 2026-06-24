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
ll powmod(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp%2==1)
            res = (__int128)res * base % MOD;
        base = (__int128)base * base % MOD;
        exp /= 2;
    }
    return (res+MOD)%MOD;
}
void solve() {
    ll l,r,k;
    cin >> l >> r >> k;

    if(k>9)
    {
        cout<<0<<endl;
        return;
    }
    if(k==1)
    {
        ll ans=(powmod(10,r)-powmod(10,l)+MOD)%MOD;
        cout<<ans<<endl;
    }
    if(k==2)
    {
        ll ans=(powmod(5,r)-powmod(5,l)+MOD)%MOD;
        cout<<ans<<endl;
    }
    if(k==3)
    {
        ll ans=(powmod(4,r)-powmod(4,l)+MOD)%MOD;
        cout<<ans<<endl;
    }
    if(k==4)
    {
        ll ans=(powmod(3,r)-powmod(3,l)+MOD)%MOD;
        cout<<ans<<endl;
    }
    if(k>4)
    {
        ll ans=(powmod(2,r)-powmod(2,l)+MOD)%MOD;
        cout<<ans<<endl;
    }
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}