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

    vll a;
    ll temp;
    cin>>temp;
    a.pb(temp);
    for(int i=1;i<n;i++)
    {
        cin>>temp;
        if(temp!=a.back())
        {
            a.pb(temp);
        }
    }

    int ans=0;
    int length=a.size();

    if(length==1 or length==2) {cout<<1<<endl; return;}

    for(int i=1;i<length-1;i++)
    {
        if(a[i]>a[i+1] and a[i]>a[i-1]) ans++;
    }

    if(a[0]>a[1]) ans++;
    if(a[length-1]>a[length-2]) ans++;

    
    cout<<ans<<endl;

}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}