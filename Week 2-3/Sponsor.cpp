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
    string l,r;

    cin>>l>>r;
    
    int length=l.length();

    if(l==r)
    {
        cout<<2*length<<endl;
        return;
    }
    int ans=0,check=0;
    for(int i=0;i<length;i++)
    {   
        if(check)
        {   
            if(l[i]=='9' and r[i]=='0')
            {
                ans++;
            }
            else
            {
                break;
            }
            continue;
        }
        if(l[i]==r[i]) ans+=2;
        if(r[i]-l[i]>=2) break;
        if(r[i]-l[i]==1) 
        {
            check=1;
            ans++;
        }
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