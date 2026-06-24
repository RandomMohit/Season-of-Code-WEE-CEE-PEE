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

    vi a(n);
    for (int &x : a) cin >> x;

    int target=a[0];

    for(int i=1;i<n;i++)
    {
        target=__gcd(target,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]/target;
    }
    sort(all(a));
    int ans=0;
    if(a[0]==1)
    {
        for(int i=1;i<n;i++)
        {
            if(a[i]!=1) ans++;
        }
        cout<<ans<<endl;
        return;
    }
    
    vi dp(a[n-1]+1,2e5+1);
    for (int &x : a) dp[x]=0;
    for(int i=a[n-1];i>0;i--)
    {   
        if(dp[i]==2e5+1) continue;
        for(int j=0;j<n;j++)
        {   
            dp[__gcd(i,a[j])]=min(dp[__gcd(i,a[j])],1+dp[i]);
        }
    }
    cout<<dp[1]+n-1<<endl;
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}