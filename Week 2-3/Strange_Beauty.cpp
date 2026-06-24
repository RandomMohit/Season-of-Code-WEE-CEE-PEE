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
const int N=2e5+1;
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#else
#define debug(x)
#endif
int dp[N];
int dupcount[N];
void solve() {
    int n;
    cin >> n;

    vi a(n);
    fill(dp,dp+N,0);
    fill(dupcount,dupcount+N,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dupcount[a[i]]++;
    }
    for(int i=1;i<N;i++)
    {
        dp[i]+=dupcount[i];
        int j=2;
        while(j*i<N)
        {
            dp[j*i]=max(dp[j*i],dp[i]);
            j++;
        }
    }
    int max_val=*max_element(dp,dp+N);
    cout<<n-max_val<<endl;
    

}

int main() {
    fast_io;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}