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

void solve() 
{

    int n;
    cin >> n;

    ll l, r;

    cin >> l >> r;

    vi a(n+1),prefix_xor(n+1,0);

    for(int i=1;i<n+1;i++)
    {
        cin>>a[i];
        prefix_xor[i]=prefix_xor[i-1]^a[i];
    }
    if(n%2==0)
    {
        n++;
        a.pb(prefix_xor[n/2]);
        prefix_xor.pb((*prefix_xor.rbegin())^(*a.rbegin()));
    }

    for(int i=n+1;i<=2*n;i++)
    {
        a.pb(prefix_xor[i/2]);
        prefix_xor.pb((*prefix_xor.rbegin())^(*a.rbegin()));
    }

    int answer=0;
    while(l>2*n)
    {
        answer^=prefix_xor[n];
        if((l/2)%2==1) break;
        l/=2;
    }
    if(l<=2*n) answer^=a[l];

    cout<<answer<<endl;
}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}