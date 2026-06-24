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
    int n,K;
    cin >> n >> K;

    vi a(n);
    for (int &x : a) cin >> x;

    vector<bool> dp(K+1,false);

    for(int i=0;i<=K;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (i>=a[j]) 
            {
                if (!dp[i-a[j]])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }

    if(dp[K]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}