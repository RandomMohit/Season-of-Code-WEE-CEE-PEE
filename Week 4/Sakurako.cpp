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

    vi a(n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    vi used(n+1);

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        int cycle_length=1;
        int x=a[i];
        used[i]=1;
        while(used[x]==0)
        {
            used[x]=1;
            x=a[x];
            cycle_length++;
        }
        ans+=(cycle_length-1)/2;

    }

    cout<<ans<<endl;

}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}