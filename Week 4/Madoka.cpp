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
    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (string &x : a) cin >> x;

    if(n==1 or m==1) {cout<<"YES"<<endl; return;}

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int count=0;
            if(a[i][j]=='1') count++;
            if(a[i+1][j]=='1') count++;
            if(a[i][j+1]=='1') count++;
            if(a[i+1][j+1]=='1') count++;
            if(count==3) {cout<<"NO"<<endl; return;}
        }
    }

    cout<<"YES"<<endl;

}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}