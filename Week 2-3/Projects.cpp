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

    vector<vll> projects(n+1,vll(3,0));
    for (int i=1;i<=n;i++) cin >> projects[i][0] >> projects[i][1] >> projects[i][2];

    sort(all(projects),[](auto &a,auto &b){return a[1]<b[1];});

    vll end_dates(n+1,0);

    for(int i=1;i<=n;i++)
    {
        end_dates[i]=projects[i][1];
    }
    vll dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int j=distance(end_dates.begin(),lower_bound(all(end_dates),projects[i][0]))-1;
        dp[i]=max(dp[i-1],dp[j]+projects[i][2]);
    }

    cout<<dp[n]<<endl;

    

}

int main() {
    fast_io;

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}